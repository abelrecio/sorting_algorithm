typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef unsigned long    qword;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned long    undefined8;
typedef unsigned short    word;
typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; // Initial Location
    dword data_loc; // Data location
};

typedef ulong size_t;

typedef long __ssize_t;

typedef __ssize_t ssize_t;

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

typedef enum Elf_ProgramHeaderType {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482
} Elf_ProgramHeaderType;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef enum Elf64_DynTag {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf64_DynTag;

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct Elf64_Dyn Elf64_Dyn, *PElf64_Dyn;

struct Elf64_Dyn {
    enum Elf64_DynTag d_tag;
    qword d_val;
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef struct NoteAbiTag NoteAbiTag, *PNoteAbiTag;

struct NoteAbiTag {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    dword abiType; // 0 == Linux
    dword requiredKernelVersion[3]; // Major.minor.patch
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[20];
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

struct evp_pkey_ctx_st {
};

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;




int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void FUN_00100630(void)

{
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void free(void *__ptr)

{
  free(__ptr);
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

ssize_t write(int __fd,void *__buf,size_t __n)

{
  ssize_t sVar1;
  
  sVar1 = write(__fd,__buf,__n);
  return sVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

ssize_t read(int __fd,void *__buf,size_t __nbytes)

{
  ssize_t sVar1;
  
  sVar1 = read(__fd,__buf,__nbytes);
  return sVar1;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

void * malloc(size_t __size)

{
  void *pvVar1;
  
  pvVar1 = malloc(__size);
  return pvVar1;
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void processEntry _start(undefined8 param_1,undefined8 param_2)

{
  undefined auStack_8 [8];
  
  __libc_start_main(main,param_2,&stack0x00000008,__libc_csu_init,__libc_csu_fini,param_1,auStack_8)
  ;
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x001006e7)
// WARNING: Removing unreachable block (ram,0x001006f3)

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x00100738)
// WARNING: Removing unreachable block (ram,0x00100744)

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  if (completed_7698 != '\0') {
    return;
  }
  __cxa_finalize(__dso_handle);
  deregister_tm_clones();
  completed_7698 = 1;
  return;
}



void frame_dummy(void)

{
  register_tm_clones();
  return;
}



undefined8 get_instructions(undefined8 param_1)

{
  int iVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  int local_20;
  int local_1c;
  undefined8 local_18;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_20 = 0;
  while (local_20 != -1) {
    local_1c = get_next_line(0,&local_18);
    if (local_1c != 1) break;
    local_20 = local_20 + 1;
    iVar1 = ft_strcmp(local_18,&DAT_00105484);
    if (iVar1 == 0) {
LAB_0010081a:
      swap_operations(param_1,local_18);
    }
    else {
      iVar1 = ft_strcmp(local_18,&DAT_00105488);
      if (iVar1 == 0) goto LAB_0010081a;
      iVar1 = ft_strcmp(local_18,&DAT_0010548c);
      if (iVar1 == 0) goto LAB_0010081a;
      iVar1 = ft_strcmp(local_18,&DAT_00105490);
      if (iVar1 == 0) {
LAB_00100860:
        push_operations(param_1,local_18);
      }
      else {
        iVar1 = ft_strcmp(local_18,&DAT_00105494);
        if (iVar1 == 0) goto LAB_00100860;
        iVar1 = ft_strcmp(local_18,&DAT_00105498);
        if (iVar1 == 0) {
LAB_001008bd:
          rotate_operations(param_1,local_18);
        }
        else {
          iVar1 = ft_strcmp(local_18,&DAT_0010549c);
          if (iVar1 == 0) goto LAB_001008bd;
          iVar1 = ft_strcmp(local_18,&DAT_001054a0);
          if (iVar1 == 0) goto LAB_001008bd;
          iVar1 = ft_strcmp(local_18,&DAT_001054a4);
          if (iVar1 == 0) {
LAB_00100917:
            reverse_operations(param_1,local_18);
          }
          else {
            iVar1 = ft_strcmp(local_18,&DAT_001054a9);
            if (iVar1 == 0) goto LAB_00100917;
            iVar1 = ft_strcmp(local_18,&DAT_001054ae);
            if (iVar1 == 0) goto LAB_00100917;
            local_20 = -1;
          }
        }
      }
    }
    ft_strdel(&local_18);
  }
  if ((local_20 == -1) || (local_1c == -1)) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return uVar2;
}



undefined8 main(int param_1,undefined8 param_2)

{
  int iVar1;
  int *__ptr;
  undefined8 uVar2;
  
  __ptr = (int *)malloc(0x68);
  if (__ptr == (int *)0x0) {
    return 0xffffffff;
  }
  if (1 < param_1) {
    iVar1 = parser(param_1,param_2,__ptr);
    if ((iVar1 == -1) || (iVar1 == -2)) {
      uVar2 = error(__ptr,iVar1);
      return uVar2;
    }
    visual(__ptr);
    iVar1 = get_instructions(__ptr);
    if (iVar1 == -1) {
      uVar2 = error(__ptr,0xfffffffd);
      return uVar2;
    }
    iVar1 = check_order_stack(__ptr);
    if ((iVar1 == 0) && (*__ptr == __ptr[8])) {
      ft_putendl(&DAT_001054b3);
    }
    else {
      ft_putendl(&DAT_001054b6);
    }
    ft_free(__ptr);
  }
  free(__ptr);
  return 0;
}



undefined8 is_few_numbers(int *param_1)

{
  undefined8 uVar1;
  
  if (*param_1 < 4) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



void sort_few_numbers(int *param_1)

{
  if (*param_1 == 3) {
    sort3_a(param_1);
  }
  if (*param_1 == 2) {
    sort2_a(param_1);
  }
  return;
}



undefined8 is_almost_sorted(int *param_1)

{
  undefined8 uVar1;
  int local_c;
  
  local_c = 0;
  while (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) <
         *(int *)(*(long *)(param_1 + 4) + ((long)local_c + 1) * 4)) {
    local_c = local_c + 1;
  }
  if ((*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) == param_1[2]) &&
     (*(int *)(*(long *)(param_1 + 4) + ((long)local_c + 1) * 4) == param_1[1])) {
    do {
      local_c = local_c + 1;
      if (*param_1 + -1 <= local_c) break;
    } while (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) <
             *(int *)(*(long *)(param_1 + 4) + ((long)local_c + 1) * 4));
    if ((local_c == *param_1 + -1) &&
       (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) < **(int **)(param_1 + 4))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



void sort_almost_sorted(int *param_1)

{
  int iVar1;
  int local_c;
  
  local_c = 0;
  while (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) != param_1[2]) {
    local_c = local_c + 1;
  }
  while ((*param_1 / 2 <= local_c && (iVar1 = check_order_stack(param_1), iVar1 != 0))) {
    operation(param_1,&DAT_001054b9);
    reverse_operations(param_1,&DAT_001054b9);
  }
  while ((local_c < *param_1 / 2 && (iVar1 = check_order_stack(param_1), iVar1 != 0))) {
    operation(param_1,&DAT_001054be);
    rotate_operations(param_1,&DAT_001054be);
  }
  return;
}



int nblen(int param_1)

{
  undefined4 local_1c;
  undefined4 local_c;
  
  local_c = 0;
  local_1c = param_1;
  if ((param_1 < 0) || (param_1 == 0)) {
    local_c = 1;
  }
  for (; local_1c != 0; local_1c = local_1c / 10) {
    local_c = local_c + 1;
  }
  return local_c;
}



int ft_lennb(char *param_1)

{
  int local_10;
  int local_c;
  
  local_c = 0;
  local_10 = 0;
  if ((*param_1 == '+') || (*param_1 == '-')) {
    local_c = 1;
  }
  for (; param_1[local_c] == '0'; local_c = local_c + 1) {
  }
  for (; param_1[local_c] != '\0'; local_c = local_c + 1) {
    local_10 = local_10 + 1;
  }
  return local_10;
}



undefined8 check_atoi(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  int local_18;
  int local_14;
  
  local_18 = 0;
  local_14 = 0;
  if (((*param_1 == '+') || (*param_1 == '-')) && (iVar1 = ft_isdigit((int)param_1[1]), iVar1 == 1))
  {
    local_18 = 1;
  }
  for (; param_1[local_18] == '0'; local_18 = local_18 + 1) {
  }
  while (iVar1 = ft_isdigit((int)param_1[local_14 + local_18]), iVar1 != 0) {
    local_14 = local_14 + 1;
  }
  iVar1 = ft_isdigit((int)param_1[local_14 + local_18]);
  if ((iVar1 == 0) && (param_1[local_14 + local_18] != '\0')) {
    uVar2 = 0xffffffff;
  }
  else {
    lVar3 = ft_atol(param_1);
    if ((lVar3 < -0x80000000) || ((0x7fffffff < lVar3 || (10 < local_14)))) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



undefined8 check_double(long param_1,int param_2)

{
  int local_10;
  int local_c;
  
  local_10 = 0;
  do {
    if (param_2 <= local_10) {
      return 0;
    }
    for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
      if ((*(int *)(param_1 + (long)local_10 * 4) == *(int *)(param_1 + (long)local_c * 4)) &&
         (local_10 != local_c)) {
        return 0xffffffff;
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}



undefined8 error(void *param_1,int param_2)

{
  if (param_2 == -1) {
    free(*(void **)((long)param_1 + 0x10));
    free(*(void **)((long)param_1 + 0x18));
  }
  else if (param_2 == -3) {
    ft_free(param_1);
  }
  free(param_1);
  write(2,"Error\n",6);
  return 0xffffffff;
}



void swap_operations(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = ft_strcmp(param_2,&DAT_001054c9);
  if ((iVar4 == 0) && (1 < *(int *)(param_1 + 0x20))) {
    lVar2 = *(long *)(param_1 + 0x10);
    iVar4 = top(param_1,0x61);
    uVar1 = *(undefined4 *)((long)iVar4 * 4 + lVar2);
    lVar2 = *(long *)(param_1 + 0x10);
    iVar4 = top(param_1,0x61);
    lVar3 = *(long *)(param_1 + 0x10);
    iVar5 = top(param_1,0x61);
    *(undefined4 *)(lVar3 + (long)iVar5 * 4) = *(undefined4 *)(lVar2 + ((long)iVar4 + 1) * 4);
    lVar2 = *(long *)(param_1 + 0x10);
    iVar4 = top(param_1,0x61);
    *(undefined4 *)(lVar2 + ((long)iVar4 + 1) * 4) = uVar1;
  }
  else {
    iVar4 = ft_strcmp(param_2,&DAT_001054cd);
    if ((iVar4 == 0) && (1 < *(int *)(param_1 + 0x24))) {
      lVar2 = *(long *)(param_1 + 0x18);
      iVar4 = top(param_1,0x62);
      uVar1 = *(undefined4 *)((long)iVar4 * 4 + lVar2);
      lVar2 = *(long *)(param_1 + 0x18);
      iVar4 = top(param_1,0x62);
      lVar3 = *(long *)(param_1 + 0x18);
      iVar5 = top(param_1,0x62);
      *(undefined4 *)(lVar3 + (long)iVar5 * 4) = *(undefined4 *)(lVar2 + ((long)iVar4 + 1) * 4);
      lVar2 = *(long *)(param_1 + 0x18);
      iVar4 = top(param_1,0x62);
      *(undefined4 *)(lVar2 + ((long)iVar4 + 1) * 4) = uVar1;
    }
    else {
      iVar4 = ft_strcmp(param_2,&DAT_001054d1);
      if (iVar4 == 0) {
        swap_operations(param_1,&DAT_001054c9);
        swap_operations(param_1,&DAT_001054cd);
      }
    }
  }
  visual(param_1);
  return;
}



void push_operations(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = ft_strcmp(param_2,&DAT_001054d5);
  if ((iVar3 == 0) && (0 < *(int *)(param_1 + 0x24))) {
    lVar1 = *(long *)(param_1 + 0x18);
    iVar3 = top(param_1,0x62);
    lVar2 = *(long *)(param_1 + 0x10);
    iVar4 = top(param_1,0x61);
    *(undefined4 *)(lVar2 + (long)iVar4 * 4 + -4) = *(undefined4 *)(lVar1 + (long)iVar3 * 4);
    lVar1 = *(long *)(param_1 + 0x18);
    iVar3 = top(param_1,0x62);
    *(undefined4 *)((long)iVar3 * 4 + lVar1) = 0;
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  else {
    iVar3 = ft_strcmp(param_2,&DAT_001054d9);
    if ((iVar3 == 0) && (0 < *(int *)(param_1 + 0x20))) {
      lVar1 = *(long *)(param_1 + 0x10);
      iVar3 = top(param_1,0x61);
      lVar2 = *(long *)(param_1 + 0x18);
      iVar4 = top(param_1,0x62);
      *(undefined4 *)(lVar2 + (long)iVar4 * 4 + -4) = *(undefined4 *)(lVar1 + (long)iVar3 * 4);
      lVar1 = *(long *)(param_1 + 0x10);
      iVar3 = top(param_1,0x61);
      *(undefined4 *)((long)iVar3 * 4 + lVar1) = 0;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    }
  }
  uVar5 = top(param_1,0x61);
  *(undefined4 *)(param_1 + 0x28) = uVar5;
  uVar5 = top(param_1,0x62);
  *(undefined4 *)(param_1 + 0x2c) = uVar5;
  visual(param_1);
  return;
}



void rotate_operations(int *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int local_10;
  
  iVar2 = ft_strcmp(param_2,&DAT_001054dd);
  if ((iVar2 == 0) && (0 < param_1[8])) {
    local_10 = top(param_1,0x61);
    uVar1 = *(undefined4 *)(*(long *)(param_1 + 4) + (long)local_10 * 4);
    while (local_10 = local_10 + 1, local_10 < *param_1) {
      *(undefined4 *)((long)local_10 * 4 + -4 + *(long *)(param_1 + 4)) =
           *(undefined4 *)(*(long *)(param_1 + 4) + (long)local_10 * 4);
    }
    *(undefined4 *)(*(long *)(param_1 + 4) + (long)*param_1 * 4 + -4) = uVar1;
  }
  else {
    iVar2 = ft_strcmp(param_2,&DAT_001054e1);
    if ((iVar2 == 0) && (0 < param_1[9])) {
      local_10 = top(param_1,0x62);
      uVar1 = *(undefined4 *)(*(long *)(param_1 + 6) + (long)local_10 * 4);
      while (local_10 = local_10 + 1, local_10 < *param_1) {
        *(undefined4 *)((long)local_10 * 4 + -4 + *(long *)(param_1 + 6)) =
             *(undefined4 *)(*(long *)(param_1 + 6) + (long)local_10 * 4);
      }
      *(undefined4 *)(*(long *)(param_1 + 6) + (long)*param_1 * 4 + -4) = uVar1;
    }
    else {
      iVar2 = ft_strcmp(param_2,&DAT_001054e5);
      if (iVar2 == 0) {
        rotate_operations(param_1,&DAT_001054dd);
        rotate_operations(param_1,&DAT_001054e1);
      }
    }
  }
  visual(param_1);
  return;
}



void reverse_operations(int *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int local_20;
  
  iVar4 = *param_1;
  iVar3 = ft_strcmp(param_2,&DAT_001054e9);
  local_20 = iVar4 + -1;
  if ((iVar3 == 0) && (0 < param_1[8])) {
    uVar1 = *(undefined4 *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 4));
    while( true ) {
      iVar4 = local_20 + -1;
      iVar3 = top(param_1,0x61);
      if (local_20 <= iVar3) break;
      *(undefined4 *)(((long)iVar4 + 1) * 4 + *(long *)(param_1 + 4)) =
           *(undefined4 *)(*(long *)(param_1 + 4) + (long)iVar4 * 4);
      local_20 = iVar4;
    }
    lVar2 = *(long *)(param_1 + 4);
    iVar4 = top(param_1,0x61);
    *(undefined4 *)(lVar2 + (long)iVar4 * 4) = uVar1;
  }
  else {
    iVar3 = ft_strcmp(param_2,&DAT_001054ee);
    if ((iVar3 == 0) && (0 < param_1[9])) {
      uVar1 = *(undefined4 *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 6));
      while( true ) {
        iVar4 = local_20 + -1;
        iVar3 = top(param_1,0x62);
        if (local_20 <= iVar3) break;
        *(undefined4 *)(((long)iVar4 + 1) * 4 + *(long *)(param_1 + 6)) =
             *(undefined4 *)(*(long *)(param_1 + 6) + (long)iVar4 * 4);
        local_20 = iVar4;
      }
      lVar2 = *(long *)(param_1 + 6);
      iVar4 = top(param_1,0x62);
      *(undefined4 *)(lVar2 + (long)iVar4 * 4) = uVar1;
    }
    else {
      iVar4 = ft_strcmp(param_2,&DAT_001054f3);
      if (iVar4 == 0) {
        reverse_operations(param_1,&DAT_001054e9);
        reverse_operations(param_1,&DAT_001054ee);
      }
    }
  }
  visual(param_1);
  return;
}



void operation(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = ft_strjoin(*(undefined8 *)(param_1 + 0x60),param_2);
  free(*(void **)(param_1 + 0x60));
  *(undefined8 *)(param_1 + 0x60) = uVar1;
  return;
}



void delete(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  while( true ) {
    lVar4 = ft_strstr(*(undefined8 *)(param_1 + 0x60),param_2);
    if (lVar4 == 0) break;
    iVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),param_2);
    iVar1 = iVar1 - (int)*(undefined8 *)(param_1 + 0x60);
    lVar4 = ft_strlen(*(undefined8 *)(param_1 + 0x60));
    lVar2 = ft_strlen(param_2);
    uVar3 = ft_strnew(lVar4 - lVar2);
    uVar3 = ft_strncpy(uVar3,*(undefined8 *)(param_1 + 0x60),(long)iVar1);
    lVar4 = *(long *)(param_1 + 0x60);
    lVar2 = ft_strlen(param_2);
    uVar3 = ft_strcat(uVar3,lVar4 + lVar2 + iVar1);
    free(*(void **)(param_1 + 0x60));
    *(undefined8 *)(param_1 + 0x60) = uVar3;
  }
  return;
}



void delete_operations(undefined8 param_1)

{
  delete(param_1,"\npa\npb");
  delete(param_1,"\npb\npa");
  delete(param_1,"\nra\nrra");
  delete(param_1,"\nrb\nrrb");
  delete(param_1,"\nrra\nra");
  delete(param_1,"\nrrb\nrb");
  delete(param_1,"\nsa\nsa");
  delete(param_1,"\nsb\nsb");
  return;
}



void replace(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  while( true ) {
    lVar5 = ft_strstr(*(undefined8 *)(param_1 + 0x60),param_2);
    if (lVar5 == 0) break;
    iVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),param_2);
    iVar1 = iVar1 - (int)*(undefined8 *)(param_1 + 0x60);
    lVar5 = ft_strlen(*(undefined8 *)(param_1 + 0x60));
    lVar2 = ft_strlen(param_2);
    lVar3 = ft_strlen(param_3);
    uVar4 = ft_strnew(lVar3 + (lVar5 - lVar2));
    uVar4 = ft_strncpy(uVar4,*(undefined8 *)(param_1 + 0x60),(long)iVar1);
    uVar4 = ft_strcat(uVar4,param_3);
    lVar5 = *(long *)(param_1 + 0x60);
    lVar2 = ft_strlen(param_2);
    uVar4 = ft_strcat(uVar4,lVar5 + lVar2 + iVar1);
    free(*(void **)(param_1 + 0x60));
    *(undefined8 *)(param_1 + 0x60) = uVar4;
  }
  return;
}



void optimize(long param_1)

{
  long lVar1;
  
  do {
    lVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),"\npa\npb");
    if (lVar1 == 0) {
      lVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),"\npb\npa");
      if (lVar1 == 0) {
        lVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),"\nra\nrra");
        if (lVar1 == 0) {
          lVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),"\nrb\nrrb");
          if (lVar1 == 0) {
            lVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),"\nrra\nra");
            if (lVar1 == 0) {
              lVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),"\nrrb\nrb");
              if (lVar1 == 0) {
                lVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),"\nsa\nsa");
                if (lVar1 == 0) {
                  lVar1 = ft_strstr(*(undefined8 *)(param_1 + 0x60),"\nsb\nsb");
                  if (lVar1 == 0) {
                    replace(param_1,"\nsa\nsb\n",&DAT_00105534);
                    replace(param_1,"\nsb\nsa\n",&DAT_00105534);
                    replace(param_1,"\nrra\nrrb\n","\nrrr\n");
                    replace(param_1,"\nrrb\nrra\n","\nrrr\n");
                    replace(param_1,"\nra\nrb\n",&DAT_00105563);
                    replace(param_1,"\nrb\nra\n",&DAT_00105563);
                    return;
                  }
                }
              }
            }
          }
        }
      }
    }
    delete_operations(param_1);
  } while( true );
}



long bubble_sort(long param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  for (local_14 = 0; local_10 = local_14, local_14 < param_2; local_14 = local_14 + 1) {
    while (local_10 = local_10 + 1, local_10 < param_2) {
      if (*(int *)(param_1 + (long)local_10 * 4) < *(int *)(param_1 + (long)local_14 * 4)) {
        uVar1 = *(undefined4 *)(param_1 + (long)local_14 * 4);
        *(undefined4 *)(param_1 + (long)local_14 * 4) =
             *(undefined4 *)(param_1 + (long)local_10 * 4);
        *(undefined4 *)((long)local_10 * 4 + param_1) = uVar1;
      }
    }
  }
  return param_1;
}



int count_argnb(undefined8 param_1)

{
  int iVar1;
  long lVar2;
  int local_18;
  int local_14;
  
  lVar2 = ft_strsplit(param_1,0x20);
  local_18 = 0;
  local_14 = 0;
  while( true ) {
    if (*(long *)(lVar2 + (long)local_18 * 8) == 0) {
      ft_tabdel(lVar2);
      if (local_14 == 0) {
        local_14 = -1;
      }
      return local_14;
    }
    iVar1 = check_atoi(*(undefined8 *)(lVar2 + (long)local_18 * 8));
    if (iVar1 == -1) break;
    local_14 = local_14 + 1;
    local_18 = local_18 + 1;
  }
  ft_tabdel(lVar2);
  return -1;
}



long get_argtable(undefined4 param_1,long param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  int local_4c;
  int local_40;
  int local_2c;
  
  lVar2 = ft_init_int(param_1);
  local_4c = param_4;
  local_40 = param_3;
  while ((*(long *)(param_2 + (long)local_40 * 8) != 0 && (lVar2 != 0))) {
    local_2c = 0;
    if ((*(long *)(param_2 + (long)local_40 * 8) != 0) &&
       (lVar3 = ft_strsplit(*(undefined8 *)(param_2 + (long)local_40 * 8),0x20), lVar3 != 0)) {
      while (*(long *)(lVar3 + (long)local_2c * 8) != 0) {
        uVar1 = ft_atoi(*(undefined8 *)(lVar3 + (long)local_2c * 8));
        *(undefined4 *)((long)local_4c * 4 + lVar2) = uVar1;
        local_2c = local_2c + 1;
        local_4c = local_4c + 1;
      }
      local_40 = local_40 + 1;
      ft_tabdel(lVar3);
    }
  }
  return lVar2;
}



void initialize(int *param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = ft_init_int(*param_1);
  *(undefined8 *)(param_1 + 0x14) = uVar2;
  uVar2 = copy_inttab(*(undefined8 *)(param_1 + 4),*(undefined8 *)(param_1 + 0x14),0,*param_1 + -1);
  *(undefined8 *)(param_1 + 0x14) = uVar2;
  uVar2 = bubble_sort(*(undefined8 *)(param_1 + 0x14),*param_1);
  *(undefined8 *)(param_1 + 0x14) = uVar2;
  param_1[1] = **(int **)(param_1 + 0x14);
  param_1[2] = *(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 0x14));
  param_1[8] = *param_1;
  param_1[9] = 0;
  if (*(long *)(param_1 + 4) != 0) {
    param_1[0xc] = *(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 4));
  }
  uVar2 = ft_init_int(1);
  *(undefined8 *)(param_1 + 0xe) = uVar2;
  param_1[0x12] = 1;
  **(int **)(param_1 + 0xe) = param_1[1];
  param_1[0x11] = 0;
  iVar1 = top(param_1,0x61);
  param_1[10] = iVar1;
  iVar1 = top(param_1,0x62);
  param_1[0xb] = iVar1;
  uVar2 = ft_strnew(1);
  *(undefined8 *)(param_1 + 0x18) = uVar2;
  return;
}



undefined8 parser(int param_1,long param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  int local_10;
  
  *param_3 = 0;
  param_3[8] = 0;
  param_3[9] = 0;
  local_10 = debug(param_3,param_2,param_1);
  while( true ) {
    if (param_1 <= local_10) {
      uVar1 = debug(param_3,param_2,param_1);
      uVar3 = get_argtable(*param_3,param_2,uVar1,0);
      *(undefined8 *)(param_3 + 4) = uVar3;
      if (*(long *)(param_3 + 4) != 0) {
        uVar3 = ft_init_int(*param_3);
        *(undefined8 *)(param_3 + 6) = uVar3;
      }
      iVar2 = check_double(*(undefined8 *)(param_3 + 4),*param_3);
      if (iVar2 == -1) {
        uVar3 = 0xffffffff;
      }
      else {
        initialize(param_3);
        uVar3 = 0;
      }
      return uVar3;
    }
    iVar2 = count_argnb(*(undefined8 *)(param_2 + (long)local_10 * 8));
    if (iVar2 == -1) {
      iVar2 = -1;
    }
    else {
      iVar2 = *param_3 + iVar2;
    }
    *param_3 = iVar2;
    if (*param_3 == -1) break;
    local_10 = local_10 + 1;
  }
  return 0xfffffffe;
}



int pibon_index(int *param_1,char param_2)

{
  int local_c;
  
  local_c = 0;
  if (param_2 == 'a') {
    local_c = param_1[10];
    while ((local_c < *param_1 + -1 &&
           (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) != param_1[0xc]))) {
      local_c = local_c + 1;
    }
    if ((local_c == *param_1 + -1) &&
       (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) == param_1[0xc])) {
      return local_c;
    }
  }
  if (param_2 == 'b') {
    local_c = param_1[0xb];
    while ((local_c < *param_1 + -1 &&
           (*(int *)(*(long *)(param_1 + 6) + (long)local_c * 4) != **(int **)(param_1 + 0xe)))) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}



ulong pivot(long param_1,char param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined8 uVar5;
  void *__ptr;
  
  if (param_2 == 'a') {
    puVar3 = (undefined8 *)(param_1 + 0x10);
  }
  else {
    puVar3 = (undefined8 *)(param_1 + 0x18);
  }
  if (((param_3 < param_4) || (param_2 != 'b')) || (*(int *)(param_1 + 0x48) < 1)) {
    uVar5 = ft_init_int((param_4 - param_3) + 1);
    uVar5 = copy_inttab(*puVar3,uVar5,param_3,param_4);
    __ptr = (void *)bubble_sort(uVar5,(param_4 - param_3) + 1);
    uVar1 = *(uint *)((long)__ptr + (long)((param_4 - param_3) / 2) * 4);
    free(__ptr);
    uVar4 = (ulong)uVar1;
  }
  else {
    remove_pibon(param_1);
    iVar2 = pibon_index(param_1,0x62);
    uVar4 = pivot(param_1,0x62,*(undefined4 *)(param_1 + 0x2c),iVar2 + -1);
  }
  return uVar4;
}



undefined4 pibon_a(int *param_1)

{
  int local_c;
  
  local_c = *param_1 + -1;
  do {
    if ((local_c <= param_1[10]) ||
       (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) !=
        *(int *)(*(long *)(param_1 + 0x14) + (long)local_c * 4))) {
      if (local_c != *param_1 + -1) {
        return *(undefined4 *)(*(long *)(param_1 + 4) + ((long)local_c + 1) * 4);
      }
      return 0;
    }
    local_c = local_c + -1;
  } while ((local_c != param_1[10]) ||
          (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) !=
           *(int *)(*(long *)(param_1 + 0x14) + (long)local_c * 4)));
  return *(undefined4 *)((long)param_1[10] * 4 + *(long *)(param_1 + 4));
}



int index_int(long param_1,int param_2,int param_3,int param_4)

{
  int local_c;
  
  local_c = param_2;
  while( true ) {
    if (param_3 < local_c) {
      return -1;
    }
    if (param_4 == *(int *)(param_1 + (long)local_c * 4)) break;
    local_c = local_c + 1;
  }
  return local_c;
}



int checkmore(long param_1,int param_2,int param_3,int param_4)

{
  int local_c;
  
  local_c = param_2;
  while( true ) {
    if (param_3 <= local_c) {
      return -1;
    }
    if (param_4 < *(int *)(param_1 + (long)local_c * 4)) break;
    local_c = local_c + 1;
  }
  return local_c;
}



void add_pibon(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int local_14;
  
  local_14 = 1;
  iVar1 = checkmore(*(undefined8 *)(param_1 + 6),param_1[0xb],*param_1 + -1,param_2);
  if ((iVar1 == -1) &&
     (puVar2 = (undefined4 *)ft_init_int(param_1[0x12] + 1), puVar2 != (undefined4 *)0x0)) {
    *puVar2 = param_2;
    for (; local_14 < param_1[0x12] + 1; local_14 = local_14 + 1) {
      puVar2[local_14] = *(undefined4 *)(*(long *)(param_1 + 0xe) + (long)local_14 * 4 + -4);
    }
    free(*(void **)(param_1 + 0xe));
    *(undefined4 **)(param_1 + 0xe) = puVar2;
    param_1[0x12] = param_1[0x12] + 1;
  }
  return;
}



void remove_pibon(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = ft_init_int(*(int *)(param_1 + 0x48) + -1);
  uVar1 = copy_inttab(*(undefined8 *)(param_1 + 0x38),uVar1,1,*(int *)(param_1 + 0x48) + -1);
  free(*(void **)(param_1 + 0x38));
  *(undefined8 *)(param_1 + 0x38) = uVar1;
  if (0 < *(int *)(param_1 + 0x48)) {
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + -1;
  }
  return;
}



void rotate_pibon(int *param_1)

{
  if ((param_1[0x11] == 1) &&
     (*(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 6)) != param_1[1])) {
    operation(param_1,&DAT_00105578);
    reverse_operations(param_1,&DAT_00105578);
    add_pibon(param_1,*(undefined4 *)((long)param_1[0xb] * 4 + *(long *)(param_1 + 6)));
  }
  return;
}



undefined8 push_back(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  if (((*(int *)(param_1 + 0x24) == 0) && (iVar1 = check_order_stack(param_1), iVar1 == 0)) &&
     (*(int *)(param_1 + 0x28) == 0)) {
    return 0;
  }
  if ((*(int *)(param_1 + 0x24) < 4) && (0 < *(int *)(param_1 + 0x24))) {
    less_than_four_numbers_at_stack_b(param_1);
  }
  push_back_in_order(param_1);
  if (*(int *)(param_1 + 0x24) != 0) {
    uVar2 = calculate_the_pibon_stack_b(param_1);
    *(undefined4 *)(param_1 + 0x40) = uVar2;
    sort_b_to_a(param_1,*(undefined4 *)(param_1 + 0x40));
    if ((*(int *)(param_1 + 0x24) < 4) && (0 < *(int *)(param_1 + 0x24))) {
      less_than_four_numbers_at_stack_b(param_1);
      iVar1 = check_order_stack(param_1);
      if (iVar1 == 0) {
        uVar2 = pibon_a(param_1);
        *(undefined4 *)(param_1 + 0x30) = uVar2;
        return 0;
      }
    }
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar2 = pibon_a(param_1);
    *(undefined4 *)(param_1 + 0x30) = uVar2;
  }
  uVar3 = push_to(param_1);
  return uVar3;
}



undefined8 push_to(int *param_1)

{
  int iVar1;
  
  do {
    iVar1 = check_order_stack(param_1);
    if ((iVar1 == 0) && (param_1[8] == *param_1)) {
      return 0;
    }
    if (param_1[8] != 0) {
      iVar1 = pibon_a(param_1);
      param_1[0xc] = iVar1;
      a_to_b(param_1);
      while (0 < param_1[0x12]) {
        if (**(int **)(param_1 + 0xe) < *(int *)((long)param_1[10] * 4 + *(long *)(param_1 + 4)))
        break;
        remove_pibon(param_1);
      }
    }
    push_back(param_1);
  } while( true );
}



void sort2_a(long param_1)

{
  if (*(int *)(*(long *)(param_1 + 0x10) + (long)*(int *)(param_1 + 0x28) * 4) <
      *(int *)(*(long *)(param_1 + 0x10) + ((long)*(int *)(param_1 + 0x28) + 1) * 4)) {
    operation(param_1,&DAT_0010557d);
    swap_operations(param_1,&DAT_0010557d);
  }
  return;
}



void sort3_a(long param_1)

{
LAB_00102b1c:
  do {
    while( true ) {
      if ((*(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10)) <
           *(int *)(((long)*(int *)(param_1 + 0x28) + 1) * 4 + *(long *)(param_1 + 0x10))) &&
         (*(int *)(((long)*(int *)(param_1 + 0x28) + 1) * 4 + *(long *)(param_1 + 0x10)) <
          *(int *)(((long)*(int *)(param_1 + 0x28) + 2) * 4 + *(long *)(param_1 + 0x10)))) {
        return;
      }
      if (*(int *)(((long)*(int *)(param_1 + 0x28) + 1) * 4 + *(long *)(param_1 + 0x10)) <=
          *(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10))) break;
      operation(param_1,&DAT_00105581);
      reverse_operations(param_1,&DAT_00105581);
    }
    if (*(int *)(((long)*(int *)(param_1 + 0x28) + 1) * 4 + *(long *)(param_1 + 0x10)) <
        *(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10))) {
      if (*(int *)(((long)*(int *)(param_1 + 0x28) + 2) * 4 + *(long *)(param_1 + 0x10)) <
          *(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10))) {
        operation(param_1,&DAT_00105586);
        rotate_operations(param_1,&DAT_00105586);
        goto LAB_00102b1c;
      }
    }
    operation(param_1,&DAT_0010557d);
    swap_operations(param_1,&DAT_0010557d);
  } while( true );
}



void less_than_four_numbers_at_stack_a(long param_1)

{
  if (*(int *)(param_1 + 0x20) == 3) {
    sort3_a(param_1);
  }
  if (*(int *)(param_1 + 0x20) == 2) {
    sort2_a(param_1);
  }
  return;
}



void sort2_b(long param_1)

{
  if (*(int *)(*(long *)(param_1 + 0x18) + (long)*(int *)(param_1 + 0x2c) * 4) <
      *(int *)(*(long *)(param_1 + 0x18) + ((long)*(int *)(param_1 + 0x2c) + 1) * 4)) {
    operation(param_1,&DAT_0010558a);
    swap_operations(param_1,&DAT_0010558a);
  }
  operation(param_1,"pa\npa\n");
  push_operations(param_1,&DAT_00105595);
  push_operations(param_1,&DAT_00105595);
  return;
}



void sort3_b(long param_1)

{
  do {
    if (*(int *)(((long)*(int *)(param_1 + 0x2c) + 1) * 4 + *(long *)(param_1 + 0x18)) <
        *(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18))) {
      if (*(int *)(((long)*(int *)(param_1 + 0x2c) + 2) * 4 + *(long *)(param_1 + 0x18)) <
          *(int *)(((long)*(int *)(param_1 + 0x2c) + 1) * 4 + *(long *)(param_1 + 0x18))) {
        operation(param_1,"pa\npa\npa\n");
        push_operations(param_1,&DAT_00105595);
        push_operations(param_1,&DAT_00105595);
        push_operations(param_1,&DAT_00105595);
        return;
      }
    }
    if (*(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18)) <
        *(int *)(((long)*(int *)(param_1 + 0x2c) + 1) * 4 + *(long *)(param_1 + 0x18))) {
      operation(param_1,&DAT_00105599);
      rotate_operations(param_1,&DAT_00105599);
    }
    else if (*(int *)(((long)*(int *)(param_1 + 0x2c) + 2) * 4 + *(long *)(param_1 + 0x18)) <
             *(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18))) {
      operation(param_1,&DAT_0010558a);
      swap_operations(param_1,&DAT_0010558a);
    }
    else {
      operation(param_1,&DAT_0010559d);
      reverse_operations(param_1,&DAT_0010559d);
    }
  } while( true );
}



void less_than_four_numbers_at_stack_b(long param_1)

{
  if (*(int *)(param_1 + 0x24) == 3) {
    sort3_b(param_1);
  }
  if (*(int *)(param_1 + 0x24) == 2) {
    sort2_b(param_1);
  }
  else {
    operation(param_1,&DAT_00105595);
    push_operations(param_1,&DAT_00105595);
  }
  return;
}



void last_check(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[8] == 2) {
    iVar1 = *(int *)((long)*param_1 * 4 + -8 + *(long *)(param_1 + 4));
    iVar2 = *(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 4));
    if (iVar1 <= iVar2) {
      iVar2 = iVar1;
    }
    **(int **)(param_1 + 0xe) = iVar2;
    if (*(int *)((long)*param_1 * 4 + -8 + *(long *)(param_1 + 4)) <
        *(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 4))) {
      operation(param_1,&DAT_001055ac);
      push_operations(param_1,&DAT_001055ac);
    }
    else {
      operation(param_1,"ra\npb\n");
      rotate_operations(param_1,&DAT_001055b7);
      push_operations(param_1,&DAT_001055ac);
    }
  }
  return;
}



void sort_from_a_to_b_first_push(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  
  lVar1 = *(long *)(param_1 + 0x10);
  iVar2 = top(param_1,0x61);
  if (*(int *)((long)iVar2 * 4 + lVar1) == *(int *)(param_1 + 4)) {
    operation(param_1,"pb\nrb\n");
    push_operations(param_1,&DAT_001055ac);
    rotate_operations(param_1,&DAT_001055c2);
  }
  else {
    lVar1 = *(long *)(param_1 + 0x10);
    iVar2 = top(param_1,0x61);
    if (*(int *)((long)iVar2 * 4 + lVar1) < param_2) {
      operation(param_1,&DAT_001055ac);
      push_operations(param_1,&DAT_001055ac);
    }
    else {
      lVar1 = *(long *)(param_1 + 0x10);
      iVar2 = top(param_1,0x61);
      if (param_2 == *(int *)((long)iVar2 * 4 + lVar1)) {
        operation(param_1,"pb\nrb\n");
        push_operations(param_1,&DAT_001055ac);
        rotate_operations(param_1,&DAT_001055c2);
        *(undefined4 *)(param_1 + 0x44) = 1;
      }
      else {
        operation(param_1,&DAT_001055b7);
        rotate_operations(param_1,&DAT_001055b7);
      }
    }
  }
  return;
}



void sort_first_push(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  while( true ) {
    iVar2 = *param_1;
    uVar1 = top(param_1,0x61);
    iVar2 = checkless(*(undefined8 *)(param_1 + 4),uVar1,iVar2,param_2);
    if (iVar2 == -1) break;
    sort_from_a_to_b_first_push(param_1,param_2);
  }
  if (param_1[0x11] == 1) {
    operation(param_1,&DAT_001055c6);
    reverse_operations(param_1,&DAT_001055c6);
  }
  if (param_2 == *(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 6))) {
    operation(param_1,"rrb\nsb\nrb\n");
    reverse_operations(param_1,&DAT_001055c6);
    swap_operations(param_1,&DAT_001055d6);
    rotate_operations(param_1,&DAT_001055c2);
  }
  add_pibon(param_1,param_2);
  return;
}



void sort_random(int *param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  
  while ((1 < param_1[8] && (iVar3 = check_order_stack(param_1), iVar3 == -1))) {
    param_1[0x11] = 0;
    iVar3 = *param_1;
    uVar2 = top(param_1,0x61);
    uVar2 = pivot(param_1,0x61,uVar2,iVar3 + -1);
    sort_first_push(param_1,uVar2);
    last_check(param_1);
  }
  while ((0 < param_1[0x12] &&
         (*(int *)((long)param_1[10] * 4 + *(long *)(param_1 + 4)) <= **(int **)(param_1 + 0xe)))) {
    remove_pibon(param_1);
  }
  lVar1 = *(long *)(param_1 + 4);
  iVar3 = top(param_1,0x61);
  param_1[0xc] = *(int *)((long)iVar3 * 4 + lVar1);
  while ((iVar3 = check_order_stack(param_1), iVar3 != 0 || (param_1[8] != *param_1))) {
    push_back(param_1);
  }
  return;
}



int top(int *param_1,char param_2)

{
  int iVar1;
  
  if (param_2 == 'a') {
    iVar1 = *param_1 - param_1[8];
  }
  else if (param_2 == 'b') {
    iVar1 = *param_1 - param_1[9];
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



long copy_inttab(long param_1,long param_2,int param_3,int param_4)

{
  undefined4 local_c;
  
  for (local_c = 0; local_c < (param_4 - param_3) + 1; local_c = local_c + 1) {
    *(undefined4 *)(param_2 + (long)local_c * 4) =
         *(undefined4 *)(param_1 + (long)(local_c + param_3) * 4);
  }
  return param_2;
}



undefined8 check_order_stack(int *param_1)

{
  int local_c;
  
  local_c = param_1[10];
  while( true ) {
    if (*param_1 <= local_c) {
      return 0;
    }
    if (*(int *)(*(long *)(param_1 + 4) + (long)local_c * 4) !=
        *(int *)(*(long *)(param_1 + 0x14) + (long)local_c * 4)) break;
    local_c = local_c + 1;
  }
  return 0xffffffff;
}



void check_top_both_stacks(long param_1)

{
  if (*(int *)(((long)*(int *)(param_1 + 0x28) + 1) * 4 + *(long *)(param_1 + 0x10)) <
      *(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10))) {
    operation(param_1,&DAT_001055da);
    swap_operations(param_1,&DAT_001055da);
  }
  if (*(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18)) <
      *(int *)(((long)*(int *)(param_1 + 0x2c) + 1) * 4 + *(long *)(param_1 + 0x18))) {
    operation(param_1,&DAT_001055de);
    swap_operations(param_1,&DAT_001055de);
  }
  return;
}



void ft_free(long param_1)

{
  free(*(void **)(param_1 + 0x10));
  free(*(void **)(param_1 + 0x18));
  free(*(void **)(param_1 + 0x50));
  free(*(void **)(param_1 + 0x38));
  free(*(void **)(param_1 + 0x60));
  return;
}



void push_back_in_order(long param_1)

{
  while( true ) {
    if (*(int *)(param_1 + 0x24) == 0) {
      return;
    }
    if (*(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18)) !=
        *(int *)((long)*(int *)(param_1 + 0x28) * 4 + -4 + *(long *)(param_1 + 0x50))) break;
    if ((0 < *(int *)(param_1 + 0x48)) &&
       (*(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18)) ==
        **(int **)(param_1 + 0x38))) {
      remove_pibon(param_1);
    }
    operation(param_1,&DAT_001055e2);
    push_operations(param_1,&DAT_001055e2);
    *(undefined4 *)(param_1 + 0x30) =
         *(undefined4 *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10));
  }
  return;
}



int calculate_the_pibon_stack_b(int *param_1)

{
  int iVar1;
  int local_c;
  
  if (param_1[0x12] < 2) {
    local_c = pivot(param_1,0x62,param_1[0xb],*param_1 + -1);
    add_pibon(param_1,local_c);
  }
  else {
    iVar1 = pibon_index(param_1,0x62);
    local_c = pivot(param_1,0x62,param_1[0xb],iVar1 + -1);
    if (local_c < **(int **)(param_1 + 0xe)) {
      local_c = **(int **)(param_1 + 0xe);
      remove_pibon(param_1);
    }
  }
  return local_c;
}



void b_to_a(long param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  if (*(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18)) < param_2) {
    if (1 < *(int *)(param_1 + 0x24)) {
      operation(param_1,&DAT_001055ee);
      rotate_operations(param_1,&DAT_001055ee);
      *param_3 = *param_3 + 1;
    }
  }
  else {
    operation(param_1,&DAT_001055e2);
    push_operations(param_1,&DAT_001055e2);
    if (param_2 == *(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10))) {
      operation(param_1,&DAT_001055e6);
      rotate_operations(param_1,&DAT_001055e6);
      *(undefined4 *)(param_1 + 0x44) = 1;
    }
    if (*(int *)(((long)*(int *)(param_1 + 0x28) + 1) * 4 + *(long *)(param_1 + 0x10)) <
        *(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10))) {
      operation(param_1,&DAT_001055ea);
      swap_operations(param_1,&DAT_001055ea);
    }
    uVar1 = pibon_a(param_1);
    *(undefined4 *)(param_1 + 0x30) = uVar1;
  }
  return;
}



void rotate_or_reverse(long param_1,int param_2)

{
  int local_14;
  
  local_14 = param_2;
  if (*(int *)(param_1 + 0x24) / 2 < param_2) {
    operation(param_1,&DAT_001055ee);
    rotate_operations(param_1,&DAT_001055ee);
  }
  else {
    for (; local_14 != 0; local_14 = local_14 + -1) {
      operation(param_1,&DAT_001055f2);
      reverse_operations(param_1,&DAT_001055f2);
    }
  }
  return;
}



void sort_b_to_a(long param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  long in_FS_OFFSET;
  undefined4 local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_14 = 0;
  while ((*(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18)) !=
          **(int **)(param_1 + 0x38) && (0 < *(int *)(param_1 + 0x24)))) {
    b_to_a(param_1,param_2,&local_14);
  }
  rotate_or_reverse(param_1,local_14);
  if (*(int *)(param_1 + 0x44) == 1) {
    operation(param_1,&DAT_001055f7);
    reverse_operations(param_1,&DAT_001055f7);
    iVar1 = check_order_stack(param_1);
    if (iVar1 != 0) {
      operation(param_1,&DAT_001055fc);
      push_operations(param_1,&DAT_001055fc);
      add_pibon(param_1,param_2);
    }
    if (*(int *)(((long)*(int *)(param_1 + 0x28) + 1) * 4 + *(long *)(param_1 + 0x10)) <
        *(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10))) {
      operation(param_1,&DAT_001055ea);
      swap_operations(param_1,&DAT_001055ea);
    }
    uVar2 = pibon_a(param_1);
    *(undefined4 *)(param_1 + 0x30) = uVar2;
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return;
}



int checkless(long param_1,int param_2,int param_3,int param_4)

{
  int local_c;
  
  local_c = param_2;
  while( true ) {
    if (param_3 <= local_c) {
      return -1;
    }
    if (*(int *)(param_1 + (long)local_c * 4) <= param_4) break;
    local_c = local_c + 1;
  }
  return local_c;
}



void less_or_equal_than_pibon(long param_1,int param_2)

{
  operation(param_1,&DAT_00105600);
  push_operations(param_1,&DAT_00105600);
  if (*(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18)) ==
      *(int *)(param_1 + 4)) {
    operation(param_1,&DAT_00105604);
    rotate_operations(param_1,&DAT_00105604);
  }
  else if (param_2 == *(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18))) {
    operation(param_1,&DAT_00105604);
    rotate_operations(param_1,&DAT_00105604);
    *(undefined4 *)(param_1 + 0x44) = 1;
  }
  if (*(int *)((long)*(int *)(param_1 + 0x2c) * 4 + *(long *)(param_1 + 0x18)) <
      *(int *)(((long)*(int *)(param_1 + 0x2c) + 1) * 4 + *(long *)(param_1 + 0x18))) {
    operation(param_1,&DAT_00105608);
    swap_operations(param_1,&DAT_00105608);
  }
  return;
}



void a_to_b(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = pibon_index(param_1,0x61);
  uVar2 = top(param_1,0x61);
  uVar1 = pivot(param_1,0x61,uVar2,uVar1);
  while( true ) {
    iVar4 = pibon_index(param_1,0x61);
    if (iVar4 - *(int *)(param_1 + 0x28) < 2) break;
    iVar4 = check_order_stack(param_1);
    if (iVar4 != -1) break;
    *(undefined4 *)(param_1 + 0x44) = 0;
    uVar2 = sort_a_to_b(param_1,uVar1,0);
    rotate_pibon_min(param_1,uVar1,uVar2);
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar4 = pibon_index(param_1,0x61);
      iVar3 = top(param_1,0x61);
      if (1 < iVar4 - iVar3) {
        operation(param_1,&DAT_00105600);
        push_operations(param_1,&DAT_00105600);
        add_pibon(param_1,uVar1);
      }
    }
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar1 = pibon_a(param_1);
    *(undefined4 *)(param_1 + 0x30) = uVar1;
  }
  return;
}



int sort_a_to_b(long param_1,int param_2,int param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  int local_28;
  
  uVar2 = pibon_a(param_1);
  *(undefined4 *)(param_1 + 0x30) = uVar2;
  local_28 = param_3;
LAB_00103e57:
  do {
    if ((*(int *)(param_1 + 0x20) == 0) ||
       (*(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10)) ==
        *(int *)(param_1 + 0x30))) {
      rotate_pibon(param_1);
      if (*(int *)(param_1 + 0x20) != 0) {
        uVar2 = pibon_a(param_1);
        *(undefined4 *)(param_1 + 0x30) = uVar2;
      }
      check_top_both_stacks(param_1);
      return local_28;
    }
    if ((*(int *)(param_1 + 0x28) != 0) &&
       (*(int *)((long)*(int *)(param_1 + 0x28) * 4 + *(long *)(param_1 + 0x10)) <= param_2)) {
      lVar1 = *(long *)(param_1 + 0x50);
      iVar3 = pibon_index(param_1,0x61);
      if (param_2 != *(int *)((long)iVar3 * 4 + -4 + lVar1)) {
        less_or_equal_than_pibon(param_1,param_2);
        goto LAB_00103e57;
      }
    }
    operation(param_1,&DAT_0010560c);
    rotate_operations(param_1,&DAT_0010560c);
    local_28 = local_28 + 1;
  } while( true );
}



void rotate_pibon_min(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_28;
  
  rotate_pibon(param_1);
  if ((param_2 != *(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 6))) &&
     (*(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 6)) != param_1[1])) {
    operation(param_1,"rrb\nsb\nrb\n");
    reverse_operations(param_1,&DAT_0010561b);
    swap_operations(param_1,&DAT_00105608);
    rotate_operations(param_1,&DAT_00105604);
    add_pibon(param_1,*(undefined4 *)((long)param_1[0xb] * 4 + *(long *)(param_1 + 6)));
  }
  param_1[0x11] = 0;
  iVar2 = index_int(*(undefined8 *)(param_1 + 4),param_1[10],*param_1 + -1,param_1[2]);
  iVar2 = pivot(param_1,0x61,iVar2 + 1,*param_1 + -1);
  local_28 = param_3;
  while( true ) {
    iVar1 = local_28 + -1;
    if (local_28 == 0) break;
    operation(param_1,&DAT_00105620);
    reverse_operations(param_1,&DAT_00105620);
    if (*(int *)((long)param_1[10] * 4 + *(long *)(param_1 + 4)) <= iVar2) {
      less_or_equal_than_pibon(param_1,iVar2);
    }
    check_top_both_stacks(param_1);
    local_28 = iVar1;
    if (iVar2 == *(int *)((long)*param_1 * 4 + -4 + *(long *)(param_1 + 6))) {
      rotate_pibon(param_1);
    }
  }
  return;
}



undefined8 debug(long param_1,long param_2,int param_3)

{
  int iVar1;
  
  if ((2 < param_3) && (iVar1 = ft_strcmp(*(undefined8 *)(param_2 + 8),&DAT_00105628), iVar1 == 0))
  {
    *(undefined4 *)(param_1 + 0x58) = 1;
    return 2;
  }
  *(undefined4 *)(param_1 + 0x58) = 0;
  return 1;
}



int column_a(long param_1,int param_2)

{
  int iVar1;
  int local_10;
  
  iVar1 = nblen(*(undefined4 *)(*(long *)(param_1 + 0x10) + (long)param_2 * 4));
  if ((*(int *)(param_1 + 0x30) == *(int *)(*(long *)(param_1 + 0x10) + (long)param_2 * 4)) &&
     (*(int *)(param_1 + 0x28) <= param_2)) {
    ft_putstr("|     * ");
  }
  else {
    ft_putstr("|       ");
  }
  ft_putnbr(*(undefined4 *)(*(long *)(param_1 + 0x10) + (long)param_2 * 4));
  local_10 = 0xb - iVar1;
  while( true ) {
    if (local_10 == 0) break;
    ft_putchar(0x20);
    local_10 = local_10 + -1;
  }
  return param_2;
}



undefined8 is_pibon(long param_1,int param_2,int param_3)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (param_2 <= local_c) {
      return 0xffffffff;
    }
    if (param_3 == *(int *)(param_1 + (long)local_c * 4)) break;
    local_c = local_c + 1;
  }
  return 1;
}



int column_b(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  
  iVar1 = nblen(*(undefined4 *)(*(long *)(param_1 + 0x18) + (long)param_2 * 4));
  iVar2 = is_pibon(*(undefined8 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x48),
                   *(undefined4 *)(*(long *)(param_1 + 0x18) + (long)param_2 * 4));
  if ((iVar2 == 1) && (*(int *)(param_1 + 0x2c) <= param_2)) {
    ft_putstr("|     * ");
  }
  else {
    ft_putstr("|       ");
  }
  ft_putnbr(*(undefined4 *)(*(long *)(param_1 + 0x18) + (long)param_2 * 4));
  local_10 = 0xb - iVar1;
  while( true ) {
    if (local_10 == 0) break;
    ft_putchar(0x20);
    local_10 = local_10 + -1;
  }
  ft_putendl(&DAT_0010563d);
  return param_2;
}



void visual(int *param_1)

{
  undefined4 uVar1;
  int local_c;
  
  local_c = -1;
  if (param_1[0x16] == 1) {
    ft_putendl(" __________________ __________________ ");
    ft_putendl("|                  |                  |");
    ft_putendl("|       a          |       b          |");
    ft_putendl("|__________________|__________________|");
    ft_putendl("|                  |                  |");
    while (local_c + 1 < *param_1) {
      uVar1 = column_a(param_1,local_c + 1);
      local_c = column_b(param_1,uVar1);
    }
    ft_putendl("|__________________|__________________|\n");
  }
  return;
}



int ft_atoi(char *param_1)

{
  int local_18;
  int local_14;
  char *local_10;
  
  local_14 = 1;
  local_18 = 0;
  for (local_10 = param_1; (('\b' < *local_10 && (*local_10 < '\x0e')) || (*local_10 == ' '));
      local_10 = local_10 + 1) {
  }
  if (*local_10 == '-') {
    local_14 = -1;
    local_10 = local_10 + 1;
  }
  else if (*local_10 == '+') {
    local_10 = local_10 + 1;
  }
  for (; ('/' < *local_10 && (*local_10 < ':')); local_10 = local_10 + 1) {
    local_18 = *local_10 + -0x30 + local_18 * 10;
  }
  return local_18 * local_14;
}



long ft_atol(char *param_1)

{
  int local_1c;
  long local_18;
  char *local_10;
  
  local_1c = 1;
  local_18 = 0;
  for (local_10 = param_1; (('\b' < *local_10 && (*local_10 < '\x0e')) || (*local_10 == ' '));
      local_10 = local_10 + 1) {
  }
  if (*local_10 == '-') {
    local_1c = -1;
    local_10 = local_10 + 1;
  }
  else if (*local_10 == '+') {
    local_10 = local_10 + 1;
  }
  for (; ('/' < *local_10 && (*local_10 < ':')); local_10 = local_10 + 1) {
    local_18 = (long)(*local_10 + -0x30) + local_18 * 10;
  }
  return local_1c * local_18;
}



undefined8 ft_isdigit(int param_1)

{
  undefined8 uVar1;
  
  if ((param_1 < 0x30) || (0x39 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



void ft_putchar(undefined param_1)

{
  undefined local_c [4];
  
  local_c[0] = param_1;
  write(1,local_c,1);
  return;
}



void ft_putnbr(undefined4 param_1)

{
  ft_putnbr_fd(param_1,1);
  return;
}



void ft_putstr(void *param_1)

{
  size_t __n;
  
  if (param_1 != (void *)0x0) {
    __n = ft_strlen(param_1);
    write(1,param_1,__n);
  }
  return;
}



void ft_putendl(long param_1)

{
  if (param_1 != 0) {
    ft_putendl_fd(param_1,1);
  }
  return;
}



long ft_strcat(long param_1,long param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  for (local_10 = 0; *(char *)(param_1 + (ulong)local_10) != '\0'; local_10 = local_10 + 1) {
  }
  for (; *(char *)(param_2 + (ulong)local_c) != '\0'; local_c = local_c + 1) {
    *(undefined *)(param_1 + (ulong)local_10) = *(undefined *)(param_2 + (ulong)local_c);
    local_10 = local_10 + 1;
  }
  *(undefined *)(param_1 + (ulong)local_10) = 0;
  return param_1;
}



int ft_strcmp(byte *param_1,byte *param_2)

{
  byte *local_18;
  byte *local_10;
  
  local_10 = param_1;
  for (local_18 = param_2; ((*local_10 == *local_18 && (*local_10 != 0)) && (*local_18 != 0));
      local_18 = local_18 + 1) {
    local_10 = local_10 + 1;
  }
  return (uint)*local_10 - (uint)*local_18;
}



void ft_strdel(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    free((void *)*param_1);
    *param_1 = 0;
  }
  return;
}



long ft_strjoin(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    lVar1 = 0;
  }
  else {
    lVar1 = ft_strlen(param_1);
    lVar2 = ft_strlen(param_2);
    lVar1 = ft_strnew(lVar2 + lVar1);
    if (lVar1 == 0) {
      lVar1 = 0;
    }
    else {
      ft_strcpy(lVar1,param_1);
      ft_strcat(lVar1,param_2);
    }
  }
  return lVar1;
}



uint ft_strlen(long param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 == 0) {
    local_c = 0;
  }
  else {
    for (; *(char *)(param_1 + (ulong)local_c) != '\0'; local_c = local_c + 1) {
    }
  }
  return local_c;
}



long ft_strncpy(long param_1,long param_2,ulong param_3)

{
  ulong local_10;
  
  for (local_10 = 0; (*(char *)(local_10 + param_2) != '\0' && (local_10 < param_3));
      local_10 = local_10 + 1) {
    *(undefined *)(local_10 + param_1) = *(undefined *)(local_10 + param_2);
  }
  for (; local_10 < param_3; local_10 = local_10 + 1) {
    *(undefined *)(local_10 + param_1) = 0;
  }
  return param_1;
}



void * ft_strnew(long param_1)

{
  void *pvVar1;
  undefined8 local_20;
  
  pvVar1 = malloc(param_1 + 1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    local_20 = param_1 + 1;
    while (local_20 != 0) {
      *(undefined *)(local_20 + -1 + (long)pvVar1) = 0;
      local_20 = local_20 + -1;
    }
  }
  return pvVar1;
}



undefined8 ft_free_strsplit(void *param_1)

{
  free(param_1);
  return 0;
}



void * ft_strsplit(char *param_1,char param_2)

{
  long *plVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  char *local_30;
  uint local_28;
  uint local_24;
  
  local_28 = 0;
  if (param_1 != (char *)0x0) {
    iVar2 = ft_count_words(param_1,(int)param_2);
    pvVar3 = malloc((long)(iVar2 + 1) << 3);
    local_30 = param_1;
    if (pvVar3 != (void *)0x0) {
      while( true ) {
        while( true ) {
          if (*local_30 == '\0') {
            *(undefined8 *)((long)pvVar3 + (ulong)local_28 * 8) = 0;
            return pvVar3;
          }
          if (param_2 != *local_30) break;
          local_30 = local_30 + 1;
        }
        local_24 = 0;
        iVar2 = ft_word_len(local_30,(int)param_2);
        plVar1 = (long *)((ulong)local_28 * 8 + (long)pvVar3);
        pvVar4 = malloc((long)iVar2 + 1);
        *plVar1 = (long)pvVar4;
        if (*plVar1 == 0) break;
        while ((param_2 != *local_30 && (*local_30 != '\0'))) {
          *(char *)((ulong)local_24 + *(long *)((long)pvVar3 + (ulong)local_28 * 8)) = *local_30;
          local_30 = local_30 + 1;
          local_24 = local_24 + 1;
        }
        *(undefined *)((ulong)local_24 + *(long *)((long)pvVar3 + (ulong)local_28 * 8)) = 0;
        local_28 = local_28 + 1;
      }
      pvVar3 = (void *)ft_free_strsplit(pvVar3);
      return pvVar3;
    }
  }
  return (void *)0x0;
}



long ft_strstr(long param_1,long param_2)

{
  long lVar1;
  uint local_10;
  uint local_c;
  
  local_10 = 0;
  lVar1 = ft_strlen(param_2);
  if (lVar1 != 0) {
    for (; *(char *)(param_1 + (ulong)local_10) != '\0'; local_10 = local_10 + 1) {
      for (local_c = 0;
          *(char *)(param_2 + (ulong)local_c) == *(char *)(param_1 + (ulong)(local_c + local_10));
          local_c = local_c + 1) {
        if (*(char *)(param_2 + (ulong)(local_c + 1)) == '\0') {
          return param_1 + (ulong)local_10;
        }
      }
    }
    param_1 = 0;
  }
  return param_1;
}



long ft_count_words(char *param_1,char param_2)

{
  long local_18;
  long local_10;
  
  local_18 = 0;
  local_10 = 0;
  if (param_2 != *param_1) {
    local_18 = 1;
  }
  for (; param_1[local_10] != '\0'; local_10 = local_10 + 1) {
    if (((param_2 == param_1[local_10]) && (param_2 != param_1[local_10 + 1])) &&
       (param_1[local_10 + 1] != '\0')) {
      local_18 = local_18 + 1;
    }
  }
  return local_18;
}



long ft_word_len(char *param_1,char param_2)

{
  char *local_20;
  long local_10;
  
  local_10 = 0;
  for (local_20 = param_1; (*local_20 != '\0' && (param_2 != *local_20)); local_20 = local_20 + 1) {
    local_10 = local_10 + 1;
  }
  return local_10;
}



undefined8 save_remainder_into_list(long *param_1,int param_2,void *param_3,int param_4)

{
  undefined8 uVar1;
  int *piVar2;
  int *local_18;
  
  for (local_18 = (int *)*param_1;
      ((local_18 != (int *)0x0 && (*(long *)(local_18 + 4) != 0)) && (param_2 != *local_18));
      local_18 = *(int **)(local_18 + 4)) {
  }
  if (((local_18 == (int *)0x0) || (param_2 != *local_18)) ||
     (*(char *)((long)param_3 + (long)param_4 + 1) == '\0')) {
    if (*(char *)((long)param_3 + (long)param_4 + 1) != '\0') {
      piVar2 = (int *)malloc(0x18);
      if (piVar2 == (int *)0x0) {
        return 0xffffffff;
      }
      uVar1 = ft_strdup((long)param_3 + (long)param_4 + 1);
      *(undefined8 *)(piVar2 + 2) = uVar1;
      *piVar2 = param_2;
      piVar2[4] = 0;
      piVar2[5] = 0;
      if (*param_1 == 0) {
        *param_1 = (long)piVar2;
      }
      else {
        *(int **)(local_18 + 4) = piVar2;
      }
    }
  }
  else {
    uVar1 = ft_strdup((long)param_3 + (long)param_4 + 1);
    *(undefined8 *)(local_18 + 2) = uVar1;
  }
  free(param_3);
  return 1;
}



long line_memory_allocation(long *param_1,int param_2)

{
  long lVar1;
  void *__ptr;
  undefined8 local_18;
  
  local_18 = 0;
  if (*param_1 == 0) {
    lVar1 = ft_strnew((long)param_2);
    *param_1 = lVar1;
    if (*param_1 == 0) {
      local_18 = 0xffffffff;
    }
  }
  else {
    __ptr = (void *)ft_strdup(*param_1);
    if (__ptr == (void *)0x0) {
      local_18 = 0xffffffff;
    }
    else {
      free((void *)*param_1);
      local_18 = ft_strlen(__ptr);
      lVar1 = ft_strnew(local_18 + param_2);
      *param_1 = lVar1;
      if (*param_1 == 0) {
        local_18 = 0xffffffff;
      }
      else {
        ft_strcpy(*param_1,__ptr);
        free(__ptr);
      }
    }
  }
  return local_18;
}



undefined8 put_buffer_into_line(void *param_1,long *param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_10;
  
  for (local_10 = 0;
      ((*(char *)((long)param_1 + (long)local_10) != '\n' &&
       (*(char *)((long)param_1 + (long)local_10) != -1)) &&
      (*(char *)((long)param_1 + (long)local_10) != '\0')); local_10 = local_10 + 1) {
  }
  iVar1 = line_memory_allocation
                    (param_2,(uint)(*(char *)((long)param_1 + (long)local_10) == '\n') + local_10);
  if (iVar1 == -1) {
    uVar2 = 0xffffffff;
  }
  else {
    ft_strncpy(*param_2 + (long)iVar1,param_1,
               (long)(int)(local_10 + (uint)(*(char *)((long)param_1 + (long)local_10) == '\n')));
    if (*(char *)((long)param_1 + (long)local_10) == '\n') {
      uVar2 = save_remainder_into_list(param_3,param_4,param_1,local_10);
    }
    else if (*(char *)((long)param_1 + (long)local_10) == '\0') {
      uVar2 = read_from_fd(param_1,param_2,param_3,param_4);
    }
    else {
      free(param_1);
      uVar2 = 1;
    }
  }
  return uVar2;
}



undefined8 read_from_fd(void *param_1,long *param_2,undefined8 param_3,int param_4)

{
  int iVar1;
  char *__buf;
  undefined8 uVar2;
  ssize_t sVar3;
  long lVar4;
  
  if (param_1 != (void *)0x0) {
    free(param_1);
  }
  __buf = (char *)malloc(0x3e9);
  if (__buf == (char *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    sVar3 = read(param_4,__buf,1000);
    iVar1 = (int)sVar3;
    if ((iVar1 < 1) || (*__buf == '\0')) {
      free(__buf);
      if (iVar1 < 0) {
        uVar2 = 0xffffffff;
      }
      else {
        if (((iVar1 == 0) && (*param_2 != 0)) && (lVar4 = ft_strlen(*param_2), lVar4 != 0)) {
          return 1;
        }
        uVar2 = 0;
      }
    }
    else {
      __buf[iVar1] = '\0';
      uVar2 = put_buffer_into_line(__buf,param_2,param_3,param_4);
    }
  }
  return uVar2;
}



undefined8 get_next_line(int param_1,undefined8 *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long in_FS_OFFSET;
  int *local_28;
  int *local_20;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  if ((param_1 < 0) || (param_2 == (undefined8 *)0x0)) {
    uVar2 = 0xffffffff;
  }
  else {
    *param_2 = 0;
    local_28 = list_3864;
    for (local_20 = list_3864; (local_20 != (int *)0x0 && (param_1 != *local_20));
        local_20 = *(int **)(local_20 + 4)) {
      local_28 = local_20;
    }
    if (local_20 == (int *)0x0) {
      uVar2 = read_from_fd(0,param_2,&list_3864,param_1);
    }
    else {
      if (local_28 == local_20) {
        list_3864 = *(int **)(list_3864 + 4);
      }
      uVar2 = ft_strdup(*(undefined8 *)(local_20 + 2));
      *(undefined8 *)(local_28 + 4) = *(undefined8 *)(local_20 + 4);
      free(*(void **)(local_20 + 2));
      free(local_20);
      uVar2 = put_buffer_into_line(uVar2,param_2,&list_3864,param_1);
    }
  }
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return uVar2;
}



void * ft_init_int(int param_1)

{
  void *pvVar1;
  undefined4 local_14;
  
  local_14 = 0;
  if (param_1 < 1) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = malloc((long)param_1 << 2);
    if (pvVar1 == (void *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      for (; local_14 < param_1; local_14 = local_14 + 1) {
        *(undefined4 *)((long)pvVar1 + (long)local_14 * 4) = 0;
      }
    }
  }
  return pvVar1;
}



void ft_tabdel(void *param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 != (void *)0x0) {
    while (*(long *)((long)param_1 + (long)local_c * 8) != 0) {
      free(*(void **)((long)param_1 + (long)local_c * 8));
      local_c = local_c + 1;
    }
    free(param_1);
  }
  return;
}



void ft_putendl_fd(long param_1,int param_2)

{
  if (param_1 != 0) {
    ft_putstr_fd(param_1,param_2);
    write(param_2,&DAT_00105709,1);
  }
  return;
}



void ft_putnbr_fd(int param_1,undefined4 param_2)

{
  undefined8 local_10;
  
  local_10 = (long)param_1;
  if (local_10 < 0) {
    ft_putchar_fd(0x2d,param_2);
    local_10 = -local_10;
  }
  if (9 < local_10) {
    ft_putnbr_fd(local_10 / 10 & 0xffffffff,param_2);
  }
  ft_putchar_fd((int)(char)((char)local_10 + (char)(local_10 / 10) * -10 + '0'),param_2);
  return;
}



void ft_putstr_fd(void *param_1,int param_2)

{
  size_t __n;
  
  if (param_1 != (void *)0x0) {
    __n = ft_strlen(param_1);
    write(param_2,param_1,__n);
  }
  return;
}



long ft_strcpy(long param_1,long param_2)

{
  undefined4 local_c;
  
  for (local_c = 0; *(char *)(param_2 + (ulong)local_c) != '\0'; local_c = local_c + 1) {
    *(undefined *)(param_1 + (ulong)local_c) = *(undefined *)(param_2 + (ulong)local_c);
  }
  *(undefined *)(param_1 + (ulong)local_c) = 0;
  return param_1;
}



undefined8 ft_strdup(undefined8 param_1)

{
  long lVar1;
  void *pvVar2;
  undefined8 uVar3;
  
  lVar1 = ft_strlen(param_1);
  pvVar2 = malloc(lVar1 + 1);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = ft_strcpy(pvVar2,param_1);
  }
  return uVar3;
}



void ft_putchar_fd(undefined param_1,int param_2)

{
  undefined local_c [4];
  
  local_c[0] = param_1;
  write(param_2,local_c,1);
  return;
}



void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  _init(param_1);
  lVar1 = 0;
  do {
    (*(code *)(&__frame_dummy_init_array_entry)[lVar1])((ulong)param_1 & 0xffffffff,param_2,param_3)
    ;
    lVar1 = lVar1 + 1;
  } while (lVar1 != 1);
  return;
}



void __libc_csu_fini(void)

{
  return;
}



void _fini(void)

{
  return;
}


