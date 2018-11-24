// https://docs.oracle.com/javase/specs/jvms/se8/html/jvms-4.html#jvms-4.7
#include <stdlib.h>
#include "constant_pool.h"
#include "classreader.h"
#include <string.h>

typedef struct AttributeInfo
{
    // 保留文件常量池的指针，后续不用每次传递了
    Cp *cp;
    void *info;
} AttributeInfo;

typedef struct ExceptionTableEntry
{
    // PC计数器起，可以理解为代码起，包括
    uint16_t startPc;
    // try-catch代码行止，不包括
    uint16_t endPc;
    // catch时处理行起，必须指向有效的code数组某一个下标
    uint16_t handlerPc;
    // catch异常类型类名
    uint16_t catchType;
} ExceptionTableEntry;

/*
 * 实际的代码（指令）存储在属性表中
 */
typedef struct AttrCode
{
    uint16_t maxStack;
    uint16_t maxLocals;
    uint32_t codeLen;
    char *code;
    // 异常表entry长度
    uint32_t eteLen;
    ExceptionTableEntry *exceptionEntrys;
    uint32_t attrLen;
    AttributeInfo *attributes;
} AttrCode;

// Deprecated过期、内部生成字段等标记位
typedef struct MarkerAttribute
{

} MarkerAttribute;

// 定长属性
typedef struct ConstantValueAttribute
{
    uint16_t constantValueIndex;
} ConstantValueAttribute;

// 方法表示
typedef struct EnclosingMethodAttribute
{
    uint16_t classIndex;
    uint16_t methodIndex;
} EnclosingMethodAttribute;

// 指向异常表
typedef struct ExceptionsAttribute
{
    uint32_t len;
    uint16_t *exceptionIndexTable[];
} ExceptionsAttribute;

// 内部类
typedef struct InnerClassInfo
{
    uint16_t innerClassInfoIndex;
    uint16_t outerClassInfoIndex;
    uint16_t innerNameIndex;
    uint16_t innerClassAccessFlags;
} InnerClassInfo;

typedef struct InnerClassesAttribute
{
    uint32_t len;
    InnerClassInfo *infos;
} InnerClassesAttribute;

// 代码行数信息，方便在出错时定位问题，但不完全准确
typedef struct LineNumberTableEntry
{
    uint16_t startPc;
    uint16_t lineNumber;
} LineNumberTableEntry;

typedef struct LineNumberTableAttribute
{
    uint32_t len;
    LineNumberTableEntry *lineNumberTable;
} LineNumberTableAttribute;

// 栈帧本地变量表
typedef struct LocalVariableTableEntry
{
    uint16_t startPc;
    uint16_t length;
    uint16_t nameIndex;
    uint16_t descriptorIndex;
    uint16_t index;
} LocalVariableTableEntry;

typedef struct LocalVariableTableAttribute
{
    u_int32_t len;
    LocalVariableTableEntry *localVariableTable;
} LocalVariableTableAttribute;

typedef struct LocalVariableTypeTableEntry
{
    uint16_t startPc;
    uint16_t length;
    uint16_t nameIndex;
    uint16_t signatureIndex;
    uint16_t index;
} LocalVariableTypeTableEntry;

typedef struct LocalVariableTypeTableAttribute
{
    u_int32_t len;
    LocalVariableTypeTableEntry *localVariableTypeTable;
} LocalVariableTypeTableAttribute;

typedef struct MethodParameter
{
    uint16_t nameIndex;
    // 参数、方法、属性、类都有权限控制标记
    uint16_t accessFlags;
} MethodParameter;

// JDK8以后可以指定编译器保留形参的名称
typedef struct MethodParameters
{
    MethodParameter *parameters;
} MethodParameters;

typedef struct SignatureAttribute
{
    uint16_t signatureIndex;
} SignatureAttribute;

// 从哪编译而来
typedef struct SourceFileAttribute
{
    uint16_t signatureIndex;
} SourceFileAttribute;

// 后续再解析的属性
typedef struct UnparsedAttribute
{
    uint32_t nameLen;
    char *name;
    uint32_t length;
    uint32_t infoLen;
    char *info;
} UnparsedAttribute;

typedef struct AttributeInfos
{
    uint32_t size;
    AttributeInfo *infos;

} Attribute;

AttributeInfo *readAttribute(ClassReader *r, Cp *cp)
{
    uint16_t attrNameIndex = readUint16(r);
    u_int32_t attrNameLen;
    char *attrName = getUtf8(cp, attrNameIndex, &attrNameLen);
    u_int32_t attrLen = readUint32(r);
    struct AttributeInfo *rs = (AttributeInfo *)malloc(sizeof(struct AttributeInfo));

    if (strcmp(attrName, "Code") == 0)
    {
    }
    else if (strcmp(attrName, "ConstantValue") == 0)
    {
    }
    else if (strcmp(attrName, "Deprecated") == 0)
    {
    }
    else if (strcmp(attrName, "Exceptions") == 0)
    {
    }
    else if (strcmp(attrName, "LineNumberTable") == 0)
    {
    }
    else if (strcmp(attrName, "LocalVariableTable") == 0)
    {
    }
    else if (strcmp(attrName, "SourceFile") == 0)
    {
    }
    else if (strcmp(attrName, "Synthetic") == 0)
    {
    }
    else if (strcmp(attrName, "MethodParameters") == 0)
    {
    }
    else
    {
    }

    return rs;
}