#pragma once


typedef struct _RTL_PROCESS_MODULE_INFORMATION {
	HANDLE Section;
	PVOID MappedBase;
	PVOID ImageBase;
	ULONG ImageSize;
	ULONG Flags;
	USHORT LoadOrderIndex;
	USHORT InitOrderIndex;
	USHORT LoadCount;
	USHORT OffsetToFileName;
	UCHAR FullPathName[256];
} RTL_PROCESS_MODULE_INFORMATION, *PRTL_PROCESS_MODULE_INFORMATION;

typedef struct _RTL_PROCESS_MODULES {
	ULONG NumberOfModules;
	RTL_PROCESS_MODULE_INFORMATION Modules[1];
} RTL_PROCESS_MODULES, *PRTL_PROCESS_MODULES;

typedef struct _KERNEL_MODULES_ENTRY {
	HANDLE Section;
	PVOID MappedBase;
	PVOID ImageBase;
	ULONG ImageSize;
	ULONG Flags;
	USHORT LoadOrderIndex;
	USHORT InitOrderIndex;
	USHORT LoadCount;
	USHORT OffsetToFileName;
	UCHAR FullPathName[256];
	CHAR ModuleName[256];
} KERNEL_MODULES_ENTRY, *PKERNEL_MODULES_ENTRY;

typedef struct _KERNEL_MODULES_INFORMATION {
	ULONG NumberOfModules;
	KERNEL_MODULES_ENTRY Modules[1];
} KERNEL_MODULES_INFORMATION, *PKERNEL_MODULES_INFORMATION;




typedef struct _ENUMERAR_DRIVERS_ENTRADA
{

	WCHAR NombreDriver[MAX_PATH];
	WCHAR RutaDriver[MAX_PATH];
	PVOID DllBase;
	ULONG SizeOfImage;
	PVOID EntryPoint;

}ENUMERAR_DRIVERS_ENTRADA, *PENUMERAR_DRIVER_ENTRADA;

typedef struct _ENUMERAR_DRIVERS_INFORMACION
{
	ULONG_PTR NumeroDeDrivers;
	ENUMERAR_DRIVERS_ENTRADA Entry[1];

}ENUMERAR_DRIVERS_INFORMACION, *PENUMERAR_DRIVERS_INFORMACION;



NTSTATUS EnumDriversByQueryInformation(OUT PVOID OutputBuffer, IN ULONG Outlengthsize);



