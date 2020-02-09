#pragma once

// source:
// https://github.com/idc/uplift/blob/master/uplift/src/syscall_error_table.hpp

#include <cstdint>

namespace kern {
enum SysError : uint64_t {
    SUCCESS = 0,          // Success!
    ePERM = 1,            // Operation not permitted
    eNOENT = 2,           // No such file or directory
    eSRCH = 3,            // No such process
    eINTR = 4,            // Interrupted system call
    eIO = 5,              // Input/output error
    eNXIO = 6,            // Device not configured
    e2BIG = 7,            // Argument list too long
    eNOEXEC = 8,          // Exec format error
    eBADF = 9,            // Bad file descriptor
    eCHILD = 10,          // No child processes
    eDEADLK = 11,         // Resource deadlock avoided
    eNOMEM = 12,          // Cannot allocate memory
    eACCES = 13,          // Permission denied
    eFAULT = 14,          // Bad address
    eNOTBLK = 15,         // Block device required
    eBUSY = 16,           // Device busy
    eEXIST = 17,          // File exists
    eXDEV = 18,           // Cross-device link
    eNODEV = 19,          // Operation not supported by device
    eNOTDIR = 20,         // Not a directory
    eISDIR = 21,          // Is a directory
    eINVAL = 22,          // Invalid argument
    eNFILE = 23,          // Too many open files in system
    eMFILE = 24,          // Too many open files
    eNOTTY = 25,          // Inappropriate ioctl for device
    eTXTBSY = 26,         // Text file busy
    eFBIG = 27,           // File too large
    eNOSPC = 28,          // No space left on device
    eSPIPE = 29,          // Illegal seek
    eROFS = 30,           // Read-only filesystem
    eMLINK = 31,          // Too many links
    ePIPE = 32,           // Broken pipe
    eDOM = 33,            // Numerical argument out of domain
    eRANGE = 34,          // Result too large
    eAGAIN = 35,          // Resource temporarily unavailable
    eINPROGRESS = 36,     // Operation now in progress
    eALREADY = 37,        // Operation already in progress
    eNOTSOCK = 38,        // Socket operation on non-socket
    eDESTADDRREQ = 39,    // Destination address required
    eMSGSIZE = 40,        // Message too long
    ePROTOTYPE = 41,      // Protocol wrong type for socket
    eNOPROTOOPT = 42,     // Protocol not available
    ePROTONOSUPPORT = 43, // Protocol not supported
    eSOCKTNOSUPPORT = 44, // Socket type not supported
    eOPNOTSUPP = 45,      // Operation not supported
    eNOTSUP = eOPNOTSUPP, // Operation not supported
    ePFNOSUPPORT = 46,    // Protocol family not supported
    eAFNOSUPPORT = 47,    // Address family not supported by protocol family
    eADDRINUSE = 48,      // Address already in use
    eADDRNOTAVAIL = 49,   // Can't assign requested address
    eNETDOWN = 50,        // Network is down
    eNETUNREACH = 51,     // Network is unreachable
    eNETRESET = 52,       // Network dropped connection on reset
    eCONNABORTED = 53,    // Software caused connection abort
    eCONNRESET = 54,      // Connection reset by peer
    eNOBUFS = 55,         // No buffer space available
    eISCONN = 56,         // Socket is already connected
    eNOTCONN = 57,        // Socket is not connected
    eSHUTDOWN = 58,       // Can't send after socket shutdown
    eTOOMANYREFS = 59,    // Too many references: can't splice
    eTIMEDOUT = 60,       // Operation timed out
    eCONNREFUSED = 61,    // Connection refused
    eLOOP = 62,           // Too many levels of symbolic links
    eNAMETOOLONG = 63,    // File name too long
    eHOSTDOWN = 64,       // Host is down
    eHOSTUNREACH = 65,    // No route to host
    eNOTEMPTY = 66,       // Directory not empty
    ePROCLIM = 67,        // Too many processes
    eUSERS = 68,          // Too many users
    eDQUOT = 69,          // Disc quota exceeded
    eSTALE = 70,          // Stale NFS file handle
    eREMOTE = 71,         // Too many levels of remote in path
    eBADRPC = 72,         // RPC struct is bad
    eRPCMISMATCH = 73,    // RPC version wrong
    ePROGUNAVAIL = 74,    // RPC prog. not avail
    ePROGMISMATCH = 75,   // Program version wrong
    ePROCUNAVAIL = 76,    // Bad procedure for program
    eNOLCK = 77,          // No locks available
    eNOSYS = 78,          // Function not implemented
    eFTYPE = 79,          // Inappropriate file type or format
    eAUTH = 80,           // Authentication error
    eNEEDAUTH = 81,       // Need authenticator
    eIDRM = 82,           // Identifier removed
    eNOMSG = 83,          // No message of desired type
    eOVERFLOW = 84,       // Value too large to be stored in data type
    eCANCELED = 85,       // Operation canceled
    eILSEQ = 86,          // Illegal byte sequence
    eNOATTR = 87,         // Attribute not found
    eDOOFUS = 88,         // Programming error
    eBADMSG = 89,         // Bad message
    eMULTIHOP = 90,       // Multihop attempted
    eNOLINK = 91,         // Link has been severed
    ePROTO = 92,          // Protocol error
    eNOTCAPABLE = 93,     // Capabilities insufficient
    eCAPMODE = 94,        // Not permitted in capability mode
    eNOTRECOVERABLE = 95, // State not recoverable
    eOWNERDEAD = 96,      // Previous owner died
    eLAST = 96,           // Must be equal largest errno
};
}