#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m'

analyze_by_phases() {
    local ops_file="$1"
    local phases_file="$2"
    
    # Leer los marcadores de fase
    local phase1_done=$(grep -c "PHASE_1_DONE" "$phases_file")
    local phase2_done=$(grep -c "PHASE_2_DONE" "$phases_file")
    
    if [ $phase1_done -eq 0 ]; then
        echo "ERROR: No phase markers found!" >&2
        local total=$(wc -l < "$ops_file")
        echo "0|0|$total"
        return
    fi
    
    # Contar operaciones por tipo para identificar fases
    local total_pb=$(grep -c "^pb$" "$ops_file")
    local total_pa=$(grep -c "^pa$" "$ops_file")
    
    # Encontrar dónde termina cada fase contando pb y pa
    local phase1_ops=0
    local phase2_ops=0
    local phase3_ops=0
    local pb_count=0
    local pa_count=0
    local in_phase=1
    
    while IFS= read -r op; do
        if [ "$op" = "pb" ]; then
            pb_count=$((pb_count + 1))
            if [ $in_phase -eq 1 ]; then
                phase1_ops=$((phase1_ops + 1))
            fi
        elif [ "$op" = "pa" ]; then
            pa_count=$((pa_count + 1))
            in_phase=2
            phase2_ops=$((phase2_ops + 1))
        else
            # Otras operaciones (ra, rb, rr, etc)
            if [ $in_phase -eq 1 ]; then
                phase1_ops=$((phase1_ops + 1))
            elif [ $in_phase -eq 2 ]; then
                phase2_ops=$((phase2_ops + 1))
            else
                phase3_ops=$((phase3_ops + 1))
            fi
        fi
        
        # Cuando terminamos todos los pa, entramos en fase 3
        if [ $pa_count -eq $total_pb ] && [ $in_phase -eq 2 ]; then
            in_phase=3
        fi
    done < "$ops_file"
    
    echo "$phase1_ops|$phase2_ops|$phase3_ops"
}

test_phases() {
    local size=$1
    local iterations=$2
    local range=$3
    
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}Phase Analysis for $size numbers${NC}"
    echo -e "${BLUE}========================================${NC}"
    
    local total_phase1=0
    local total_phase2=0
    local total_phase3=0
    local total_moves=0
    
    for i in $(seq 1 $iterations); do
        ARG=$(shuf -i 1-$range -n $size | tr '\n' ' ')
        
        # Capturar stdout (operaciones) y stderr (marcadores) por separado
        ./push_swap $ARG > /tmp/ps_ops_$$ 2> /tmp/ps_phases_$$
        
        LINES=$(wc -l < /tmp/ps_ops_$$)
        
        # Analizar fases
        STATS=$(analyze_by_phases "/tmp/ps_ops_$$" "/tmp/ps_phases_$$")
        IFS='|' read -r p1 p2 p3 <<< "$STATS"
        
        total_phase1=$((total_phase1 + p1))
        total_phase2=$((total_phase2 + p2))
        total_phase3=$((total_phase3 + p3))
        total_moves=$((total_moves + LINES))
        
        echo -e "${GREEN}Test $i:${NC} Total=$LINES | P1=$p1 | P2=$p2 | P3=$p3"
    done
    
    rm -f /tmp/ps_ops_$$ /tmp/ps_phases_$$
    
    local avg_phase1=$((total_phase1 / iterations))
    local avg_phase2=$((total_phase2 / iterations))
    local avg_phase3=$((total_phase3 / iterations))
    local avg_total=$((total_moves / iterations))
    
    if [ $avg_total -eq 0 ]; then
        echo -e "${RED}ERROR: Average total is 0${NC}"
        return
    fi
    
    local p1_percent=$((avg_phase1 * 100 / avg_total))
    local p2_percent=$((avg_phase2 * 100 / avg_total))
    local p3_percent=$((avg_phase3 * 100 / avg_total))
    
    echo ""
    echo -e "${CYAN}========================================${NC}"
    echo -e "${CYAN}PHASE BREAKDOWN (Average)${NC}"
    echo -e "${CYAN}========================================${NC}"
    echo -e "Total moves: $avg_total"
    echo ""
    echo -e "${YELLOW}Phase 1 - Push to B:${NC}      $avg_phase1 moves ($p1_percent%)"
    echo -e "${YELLOW}Phase 2 - Insert in A:${NC}    $avg_phase2 moves ($p2_percent%)"
    echo -e "${YELLOW}Phase 3 - Rotate to min:${NC}  $avg_phase3 moves ($p3_percent%)"
    echo ""
    
    echo -e "${BLUE}Analysis:${NC}"
    local max_phase="Phase 1 (Push to B)"
    local max_val=$avg_phase1
    local max_percent=$p1_percent
    
    if [ $avg_phase2 -gt $max_val ]; then
        max_phase="Phase 2 (Insert in A)"
        max_val=$avg_phase2
        max_percent=$p2_percent
    fi
    
    if [ $avg_phase3 -gt $max_val ]; then
        max_phase="Phase 3 (Rotate to min)"
        max_val=$avg_phase3
        max_percent=$p3_percent
    fi
    
    echo -e "  🎯 Most expensive: ${RED}$max_phase${NC} with $max_val moves ($max_percent%)"
    echo ""
    
    if [ $p2_percent -gt 60 ]; then
        echo -e "  ⚠️  ${YELLOW}Phase 2 >60% - consider optimizing target calculation${NC}"
    fi
    
    if [ $p3_percent -gt 15 ]; then
        echo -e "  ⚠️  ${YELLOW}Phase 3 >15% - stack organization could be better${NC}"
    fi
    
    if [ $p1_percent -lt 10 ]; then
        echo -e "  ⚠️  ${YELLOW}Phase 1 <10% - consider pushing more to B${NC}"
    fi
    
    if [ $p2_percent -ge 50 ] && [ $p2_percent -le 70 ]; then
        echo -e "  ✅ ${GREEN}Phase 2 well balanced (50-70%)${NC}"
    fi
    
    echo ""
    
    # Nota
    if [ $size -eq 100 ]; then
        if [ $avg_total -lt 700 ]; then
            echo -e "${GREEN}Grade: 5/5 ⭐⭐⭐⭐⭐${NC}"
        elif [ $avg_total -lt 900 ]; then
            echo -e "${YELLOW}Grade: 4/5 ⭐⭐⭐⭐${NC}"
        elif [ $avg_total -lt 1100 ]; then
            echo -e "${YELLOW}Grade: 3/5 ⭐⭐⭐${NC}"
        else
            echo -e "${RED}Grade: <3/5${NC}"
        fi
    elif [ $size -eq 500 ]; then
        if [ $avg_total -lt 5500 ]; then
            echo -e "${GREEN}Grade: 5/5 ⭐⭐⭐⭐⭐${NC}"
        elif [ $avg_total -lt 7000 ]; then
            echo -e "${YELLOW}Grade: 4/5 ⭐⭐⭐⭐${NC}"
        elif [ $avg_total -lt 8500 ]; then
            echo -e "${YELLOW}Grade: 3/5 ⭐⭐⭐${NC}"
        else
            echo -e "${RED}Grade: <3/5${NC}"
        fi
    fi
    
    echo ""
}

echo -e "${BLUE}"
echo "╔═══════════════════════════════════════╗"
echo "║     PUSH_SWAP PHASE ANALYSIS         ║"
echo "╚═══════════════════════════════════════╝"
echo -e "${NC}"

test_phases 100 30 1000
test_phases 500 10 5000

echo -e "${BLUE}╔═══════════════════════════════════════╗${NC}"
echo -e "${BLUE}║         TESTING COMPLETED!           ║${NC}"
echo -e "${BLUE}╚═══════════════════════════════════════╝${NC}"
