#include <memory>
#include <gtest/gtest.h>
#include "TerminalInput.h"

TEST(terminalTest, oneLineInput){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    ASSERT_EQ("Hello World", t1->getData("echo -n Hello World"));
};

TEST(terminalTest, inputWithWhiteSpace){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    ASSERT_EQ("Hello World\n", t1->getData("echo Hello World"));
};

TEST(terminalTest, twoLineInput){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    ASSERT_EQ("Hello\nWorld\n", t1->getData("bash -c \"echo -e 'Hello\nWorld'\""));
};

TEST(terminalTest, twoFlags){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    ASSERT_EQ("Hello\nWorld", t1->getData("bash -c \"echo -ne 'Hello\nWorld'\""));
};

TEST(terminalTest, fileContent){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    ASSERT_EQ("T\ne\ns\nt\n", t1->getData("cat inputTest.txt"));

};

TEST(terminalTest, deleteFirstChar){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde";
    ASSERT_EQ("_bcde",t1->deleteChar(testString,'a'));

};

TEST(terminalTest, deleteSecondChar){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde";
    ASSERT_EQ("a_cde",t1->deleteChar(testString,'b'));

};

TEST(terminalTest, deleteLastChar){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde";
    ASSERT_EQ("abcd_",t1->deleteChar(testString,'e'));

};

TEST(terminalTest, tryToDeleteCharThatIsNotIncludedInString){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde";
    ASSERT_EQ("abcde",t1->deleteChar(testString,'z'));

};

TEST(terminalTest, deleteCharInTheMiddleOfSecondWord){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde xyz";
    ASSERT_EQ("abcde x_z",t1->deleteChar(testString,'y'));

};

TEST(terminalTest, deleteCharInTheStartOfSecondWord){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde xyz";
    ASSERT_EQ("abcde _yz",t1->deleteChar(testString,'x'));

};

TEST(terminalTest, tryToDeleteCharThatIsNotIncludedInTwoStrings){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde xyz";
    ASSERT_EQ("abcde xyz",t1->deleteChar(testString,'g'));

};

TEST(terminalTest, deleteSpace){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde xyz";
    ASSERT_EQ("abcde_xyz",t1->deleteChar(testString,' '));

};

TEST(terminalTest, deleteCharInInputWithNewLineChar){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde\nxyz";
    ASSERT_EQ("abc_e\nxyz",t1->deleteChar(testString,'d'));

};

TEST(terminalTest, deleteNewLineChar){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = "abcde\nxyz";
    ASSERT_EQ("abcde_xyz",t1->deleteChar(testString,'\n'));

};

TEST(terminalTest, deleteCharFronEchoInputWithFlagN){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = t1->getData("echo -n Hello World");
    ASSERT_EQ("He__o Wor_d",t1->deleteChar(testString,'l'));

};

TEST(terminalTest, deleteCharFronEchoInput){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = t1->getData("echo Hello World");
    ASSERT_EQ("He__o Wor_d\n",t1->deleteChar(testString,'l'));

};

TEST(terminalTest, deleteCharFronEchoInputWithTwoFlags){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = t1->getData("bash -c \"echo -ne 'Hello\nWorld'\"");
    ASSERT_EQ("He__o\nWor_d",t1->deleteChar(testString,'l'));

};

TEST(terminalTest, deleteDoubleNewLineChar){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = t1->getData("bash -c \"echo -e 'Hello\nWorld'\"");
    ASSERT_EQ("Hello_World_",t1->deleteChar(testString,'\n'));

};

TEST(terminalTest, deleteFirstCharFromTxtFile){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = t1->getData("cat inputTest.txt");
    ASSERT_EQ("_\ne\ns\nt\n",t1->deleteChar(testString,'T'));

};

TEST(terminalTest, deleteLastCharFromTxtFile){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = t1->getData("cat inputTest.txt");
    ASSERT_EQ("T\ne\ns\n_\n",t1->deleteChar(testString,'t'));

};

TEST(terminalTest, deleteNewLineCharFromTxtFile){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    std::string testString = t1->getData("cat inputTest.txt");
    ASSERT_EQ("T_e_s_t_",t1->deleteChar(testString,'\n'));

};
int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();




}
