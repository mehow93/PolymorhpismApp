#include <memory>
#include <gtest/gtest.h>
#include "TerminalInput.h"
#include "Operations.h"
#include "FileInput.h"

TEST(terminalTest, oneLineInput){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    EXPECT_EQ("Hello World", t1->getData("echo -n Hello World"));
};

TEST(terminalTest, inputWithWhiteSpace){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    EXPECT_EQ("Hello World\n", t1->getData("echo Hello World"));
};

TEST(terminalTest, twoLineInput){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    EXPECT_EQ("Hello\nWorld\n", t1->getData("bash -c \"echo -e 'Hello\nWorld'\""));
};

TEST(terminalTest, twoFlags){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    EXPECT_EQ("Hello\nWorld", t1->getData("bash -c \"echo -ne 'Hello\nWorld'\""));
};

TEST(terminalTest, fileContent){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>();
    EXPECT_EQ("T\ne\ns\nt\n", t1->getData("cat inputTest.txt"));

};

TEST(terminalTest, deleteFirstChar){
    std::string testString = "abcde";
    DeleteChar d1;
    EXPECT_EQ("_bcde",d1.deleteChar(testString,'a'));

};

TEST(terminalTest, deleteSecondChar){
    std::string testString = "abcde";
    DeleteChar d1;
    EXPECT_EQ("a_cde",d1.deleteChar(testString,'b'));

};

TEST(terminalTest, deleteLastChar){
    std::string testString = "abcde";
    DeleteChar d1;
    EXPECT_EQ("abcd_",d1.deleteChar(testString,'e'));

};

TEST(terminalTest, tryToDeleteCharThatIsNotIncludedInString){
    std::string testString = "abcde";
    DeleteChar d1;
    EXPECT_EQ("abcde",d1.deleteChar(testString,'z'));

};

TEST(terminalTest, deleteCharInTheMiddleOfSecondWord){
    std::string testString = "abcde xyz";
    DeleteChar d1;
    EXPECT_EQ("abcde x_z",d1.deleteChar(testString,'y'));

};

TEST(terminalTest, deleteCharInTheStartOfSecondWord){
    DeleteChar d1;
    std::string testString = "abcde xyz";
    ASSERT_EQ("abcde _yz",d1.deleteChar(testString,'x'));

};

TEST(terminalTest, tryToDeleteCharThatIsNotIncludedInTwoStrings){
    DeleteChar d1;
    std::string testString = "abcde xyz";
    EXPECT_EQ("abcde xyz",d1.deleteChar(testString,'g'));

};

TEST(terminalTest, deleteSpace){
    DeleteChar d1;
    std::string testString = "abcde xyz";
    EXPECT_EQ("abcde_xyz",d1.deleteChar(testString,' '));

};

TEST(terminalTest, deleteCharInInputWithNewLineChar){
    DeleteChar d1;
    std::string testString = "abcde\nxyz";
    EXPECT_EQ("abc_e\nxyz",d1.deleteChar(testString,'d'));

};

TEST(terminalTest, deleteNewLineChar){
    DeleteChar d1;
    std::string testString = "abcde\nxyz";
    EXPECT_EQ("abcde_xyz",d1.deleteChar(testString,'\n'));

};

TEST(terminalInputClassTest, settingContents){
    TerminalInput t1;
    std::string data = t1.getData("echo -n Hello World");
    t1.setOriginalContent(data);
    ReverseData r1;
    std::string result = r1.reverseData(data);
    t1.setProcessedContent(result);
    ASSERT_EQ("Hello World",t1.getOrginalContent());
    ASSERT_EQ("dlroW olleH",t1.getProcessesContent());
    EXPECT_NE(t1.getOrginalContent(),t1.getProcessesContent());

};
TEST(terminalInputClassTest, deleteCharFromEchoInputWithFlagN){
    TerminalInput t1;
    std::string data = t1.getData("echo -n Hello World");
    t1.setOriginalContent(data);
    DeleteChar del;
    std::string result = del.deleteChar(t1.getOrginalContent(),'l');
    t1.setProcessedContent(result);
    EXPECT_EQ("He__o Wor_d",t1.getProcessesContent());

};

TEST(terminalInputClassTest, reverseOneLineInput){
    TerminalInput t1;
    std::string data = t1.getData("echo -n Hello World");
    ReverseData r1;
    std::string result = r1.reverseData(data);
    t1.setProcessedContent(result);
    t1.setOriginalContent(data);
    EXPECT_EQ("dlroW olleH",t1.getProcessesContent());
};

TEST(terminalInputClassTest, deleteCharFronEchoInput){
    TerminalInput t1;
    std::string data = t1.getData("echo -n Hello World");
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'l');
    t1.setProcessedContent(result);
    EXPECT_EQ("He__o Wor_d",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteCharFronEchoInputWithTwoFlags){
    TerminalInput t1;
    std::string data = t1.getData("bash -c \"echo -ne 'Hello\nWorld'\"");
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'l');
    t1.setProcessedContent(result);
    EXPECT_EQ("He__o\nWor_d",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteDoubleNewLineChar){
    TerminalInput t1;
    std::string data = t1.getData("bash -c \"echo -ne 'Hello\nWorld\n'\"");
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'\n');
    t1.setProcessedContent(result);
    EXPECT_EQ("Hello_World_",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteFirstCharFromTxtFile){
    TerminalInput t1;
    std::string data = t1.getData("cat inputTest.txt");
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'T');
    t1.setProcessedContent(result);
    EXPECT_EQ("_\ne\ns\nt\n",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteLastCharFromTxtFile){
    TerminalInput t1;
    std::string data = t1.getData("cat inputTest.txt");
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'t');
    t1.setProcessedContent(result);
    EXPECT_EQ("T\ne\ns\n_\n",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteNewLineCharFromTxtFile){
    TerminalInput t1;
    std::string data = t1.getData("cat inputTest.txt");
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'\n');
    t1.setProcessedContent(result);
    EXPECT_EQ("T_e_s_t_",t1.getProcessesContent());

};

TEST(FileInputClassGetDataTest, fileWithSingleLine){
    FileInput f1;
    EXPECT_EQ("Hello World\n",f1.getData("singleLineTest.txt"));

}

TEST(FileInputClassGetDataTest, fileWithFewLines){
    FileInput f1;
    EXPECT_EQ("T\ne\ns\nt\n",f1.getData("test.txt"));

}

TEST(FileInputClassGetDataTest, fileWithTwoLines){
    FileInput f1;
    EXPECT_EQ("Hello World\nHello user\n",f1.getData("helloUser.txt"));

}

TEST(FileInputClassGetDataTest, fileThatDoesntExist){
    FileInput f1;
    EXPECT_EQ("File doesn't exist!",f1.getData("a.txt"));

}

TEST(FileInputClassGetDataTest, emptyFile){
    FileInput f1;
    EXPECT_EQ("",f1.getData("emptyFile.txt"));

}
int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();




}
