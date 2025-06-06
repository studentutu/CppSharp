enum FlagEnum
{
    A = 1 << 0,
    B = 1 << 1,
    C = 1 << 2,
    D = 1 << 3,
};

enum FlagEnum2
{
    A1 = 1 << 0,
    B1 = 3,
    C1 = 1 << 2,
    D1 = 1 << 4,
};

enum class BoolEnum : bool
{
    True = true,
    False = false,
};

enum class UCharEnum : unsigned char
{
    A = 1 << 0,
    B = 1 << 1,
    C = 1 << 2,
    D = 1 << 3,
};

class Foo
{
    void toIgnore() {}
};
void FooStart(Foo*, int);

struct TestRename
{
    int lowerCaseMethod();
    int lowerCaseField;
};

/// <summary>A simple test.</summary>
class TestCommentsPass
{
};

/// <summary>A more complex test.</summary>
class TestCommentsPass2
{
public:
    /// <summary>Gets a value</summary>
    /// <returns>One</returns>
    float GetValueWithComment()
    {
        return 1.0f;
    }

    /// <summary>Sets a value. Get it with <see cref="GetValueWithComment"/></summary>
    /// <param name="value">The value to set</param>
    /// <returns>The parameter (typeof<float>)</returns>
    float SetValueWithParamComment(float value)
    {
        return value;
    }

    /// <summary>
    /// This method changes the point's location by
    /// the given x- and y-offsets.
    /// For example:
    /// <code>
    /// Point p = new Point(3, 5);
    /// p.Translate(-1, 3);
    /// </code>
    /// results in <c>p</c>'s having the value (2, 8).
    /// <see cref="Move"/>
    /// </summary>
    /// <param name="dx">The relative x-offset.</param>
    /// <param name="dy">The relative y-offset.</param>
    void Translate(int dx, int dy)
    {
    }
};

struct TestReadOnlyProperties
{
    int readOnlyProperty;
    int getReadOnlyPropertyMethod() { return 0; }
    void setReadOnlyPropertyMethod(int value) {}
};

#define TEST_ENUM_ITEM_NAME_0 0
#define TEST_ENUM_ITEM_NAME_1 0x1
#define TEST_ENUM_ITEM_NAME_2 0x2U

enum
{
    TEST_ENUM_ITEM_NAME_3 = 3
};

// Test #defines at underlying type break points.
#define TEST_ENUM_MAX_SBYTE 127
#define TEST_ENUM_MAX_BYTE 255
#define TEST_ENUM_MAX_SHORT 32767
#define TEST_ENUM_MAX_USHORT 65535
#define TEST_ENUM_MAX_INT 2147483647
#define TEST_ENUM_MAX_UINT 4294967295
#define TEST_ENUM_MAX_LONG 9223372036854775807
#define TEST_ENUM_MAX_ULONG 18446744073709551615

#define TEST_ENUM_MIN_SBYTE -128
#define TEST_ENUM_MIN_SHORT -32768
#define TEST_ENUM_MIN_INT -2147483648
#define TEST_ENUM_MIN_LONG -9223372036854775808

// Test #defines with bit operators
#define TEST_BITWISE_OR_1 0x7F | 0x80
#define TEST_BITWISE_AND_1 0x7F & 0xFF
#define TEST_BITWISE_AND_2 0x73 & -1
#define TEST_BITWISE_AND_3 0x42 & ~0x2
#define TEST_BITWISE_XOR_1 0x7F ^ 0x03
#define TEST_BITWISE_SHIFT_1 0x2A828670572C << 1
#define TEST_NEGATIVE_HEX_1 -0xFC84D76B0482
#define TEST_NEGATIVE_EXPR_1 27 - 9223372036854775807
#define TEST_INT32_MINVALUE -2147483648;
#define TEST_INT64_MAXVALUE 9223372036854775807
#define TEST_UINT64_MAXVALUE 18446744073709551615
#define TEST_LONG_PLUS_INT 2147483648 + 5
#define TEST_INT_PLUS_LONG 5 + 2147483648

// TestStructInheritance
struct S1
{
    int F1, F2;
};
struct S2 : S1
{
    int F3;
};

// Tests unnamed enums
enum
{
    Unnamed_Enum_1_A = 1,
    Unnamed_Enum_1_B = 2
};
enum
{
    Unnamed_Enum_2_A = 3,
    Unnamed_Enum_2_B = 4
};

// Tests unique name for unnamed enums across translation units
#include "Enums.h"
enum
{
    UnnamedEnumB1,
    EnumUnnamedB2
};

struct TestCheckAmbiguousFunctionsPass
{
    // Tests removal of const method overloads
    int Method();
    int Method() const;
    int Method(int x);
    int Method(int x) const;
};

class TestCheckStaticClass
{
public:
    static int Method();
    static int Method(int x);

    constexpr static float ConstExprStatic = 3.0f;
    inline static float InlineStatic = 1.0f;

private:
    inline static float PrivateInlineStatic = 1.0f;
};

struct TestCheckStaticStruct
{
    static int Method();
    static int Method(int x);

    constexpr static float ConstExprStatic = 3.0f;
    inline static float InlineStatic = 1.0f;
};

class TestCheckStaticClassDeleted
{
public:
    TestCheckStaticClassDeleted() = delete;

    static int Method();
    static int Method(int x);

    constexpr static float ConstExprStatic = 3.0f;
    inline static float InlineStatic = 1.0f;

private:
    inline static float PrivateInlineStatic = 1.0f;
};

class TestCheckNonStaticClass
{
public:
    TestCheckNonStaticClass() = default;

    static int Method();
    static int Method(int x);

    constexpr static float ConstExprStatic = 3.0f;
    inline static float InlineStatic = 1.0f;

private:
    inline static float PrivateInlineStatic = 1.0f;

    float NonStatic = 1.0f;
};

#define CS_INTERNAL
struct TestMethodAsInternal
{
    int CS_INTERNAL beInternal();
};

class ClassWithAbstractOperator
{
    virtual operator int() = 0;
};

enum ConnectionRole
{
    Role1,
    Role2
};

bool ConnectionRoleToString(const ConnectionRole& role, const char* role_str);

class TestFlattenAnonymousTypesToFields
{
    /* TODO: Enable this code (and respective test in TestPasses).
    public:
        union
        {
            int Public;
        };
    */
protected:
    union
    {
        int Protected;
    };
};

class TestExtractInterfacePass
{
public:
    void DoSomething();
};
