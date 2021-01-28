#include <memory>
#include <gtest/gtest.h>
#include "TerminalInput.h"
#include "Operations.h"
#include "FileInput.h"
#include "StdinInput.h"

TEST(terminalTest, oneLineInput){
    std:: unique_ptr<Input> t1 = std::make_unique<TerminalInput>("echo -n Hello World");
    EXPECT_EQ("Hello World", t1->getData());
};

TEST(terminalTest, inputWithWhiteSpace){
    std:: unique_ptr<Input> t1 = std::make_unique<TerminalInput>("echo Hello World");
    EXPECT_EQ("Hello World\n", t1->getData());
};

TEST(terminalTest, twoLineInput){
    std:: unique_ptr<Input>t1 = std::make_unique<TerminalInput>("bash -c \"echo -e 'Hello\nWorld'\"");
    EXPECT_EQ("Hello\nWorld\n", t1->getData());
};

TEST(terminalTest, twoFlags){
    std::unique_ptr<Input> t1 = std::make_unique<TerminalInput>("bash -c \"echo -ne 'Hello\nWorld'\"");
    EXPECT_EQ("Hello\nWorld", t1->getData());
};

TEST(terminalTest, fileContent){
    std:: unique_ptr<Input> t1 = std::make_unique<TerminalInput>("cat inputTest.txt");
    EXPECT_EQ("T\ne\ns\nt\n", t1->getData());

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
    TerminalInput t1("echo -n Hello World");
    std::string data = t1.getData();
    t1.setOriginalContent(data);
    ReverseData r1;
    std::string result = r1.reverseData(data);
    t1.setProcessedContent(result);
    ASSERT_EQ("Hello World",t1.getOrginalContent());
    ASSERT_EQ("dlroW olleH",t1.getProcessesContent());
    EXPECT_NE(t1.getOrginalContent(),t1.getProcessesContent());

};
TEST(terminalInputClassTest, deleteCharFromEchoInputWithFlagN){
    TerminalInput t1("echo -n Hello World");
    std::string data = t1.getData();
    t1.setOriginalContent(data);
    DeleteChar del;
    std::string result = del.deleteChar(t1.getOrginalContent(),'l');
    t1.setProcessedContent(result);
    EXPECT_EQ("He__o Wor_d",t1.getProcessesContent());

};

TEST(terminalInputClassTest, reverseOneLineInput){
    TerminalInput t1("echo -n Hello World");
    std::string data = t1.getData();
    ReverseData r1;
    std::string result = r1.reverseData(data);
    t1.setProcessedContent(result);
    t1.setOriginalContent(data);
    EXPECT_EQ("dlroW olleH",t1.getProcessesContent());
};

TEST(terminalInputClassTest, deleteCharFronEchoInput){
    TerminalInput t1("echo -n Hello World");
    std::string data = t1.getData();
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'l');
    t1.setProcessedContent(result);
    EXPECT_EQ("He__o Wor_d",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteCharFronEchoInputWithTwoFlags){
    TerminalInput t1("bash -c \"echo -ne 'Hello\nWorld'\"");
    std::string data = t1.getData();
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'l');
    t1.setProcessedContent(result);
    EXPECT_EQ("He__o\nWor_d",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteDoubleNewLineChar){
    TerminalInput t1("bash -c \"echo -ne 'Hello\nWorld\n'\"");
    std::string data = t1.getData();
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'\n');
    t1.setProcessedContent(result);
    EXPECT_EQ("Hello_World_",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteFirstCharFromTxtFile){
    TerminalInput t1("cat inputTest.txt");
    std::string data = t1.getData();
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'T');
    t1.setProcessedContent(result);
    EXPECT_EQ("_\ne\ns\nt\n",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteLastCharFromTxtFile){
    TerminalInput t1("cat inputTest.txt");
    std::string data = t1.getData();
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'t');
    t1.setProcessedContent(result);
    EXPECT_EQ("T\ne\ns\n_\n",t1.getProcessesContent());

};

TEST(terminalInputClassTest, deleteNewLineCharFromTxtFile){
    TerminalInput t1("cat inputTest.txt");
    std::string data = t1.getData();
    t1.setOriginalContent(data);
    DeleteChar d1;
    std::string result = d1.deleteChar(data,'\n');
    t1.setProcessedContent(result);
    EXPECT_EQ("T_e_s_t_",t1.getProcessesContent());

};

TEST(fileInputClassGetDataTest, fileWithSingleLine){
    FileInput f1("singleLineTest.txt");
    EXPECT_EQ("Hello World\n",f1.getData());

}

TEST(fileInputClassGetDataTest, fileWithFewLines){
    FileInput f1("test.txt");
    EXPECT_EQ("T\ne\ns\nt\n",f1.getData());

}

TEST(fileInputClassGetDataTest, fileWithTwoLines){
    FileInput f1("helloUser.txt");
    EXPECT_EQ("Hello World\nHello user\n",f1.getData());

}

TEST(fileInputClassGetDataTest, fileThatDoesntExist){
    FileInput f1("a.txt");
    EXPECT_EQ("File doesn't exist!",f1.getData());

}

TEST(fileInputClassGetDataTest, emptyFile){
    FileInput f1("emptyFile.txt");
    EXPECT_EQ("",f1.getData());

}

TEST(fileInputClassTest, defaultValuesTest){
    FileInput f1("test.txt");
    ASSERT_EQ("defaultData",f1.getOrginalContent());
    ASSERT_EQ("defaultData",f1.getProcessesContent());
    EXPECT_EQ(f1.getOrginalContent(),f1.getProcessesContent());

}

TEST(fileInputClassTest, virtualGetDataTest){
    std::unique_ptr<Input> t1 = std::make_unique<FileInput>("singleLineTest.txt");
    t1->setOriginalContent(t1->getData());
    EXPECT_EQ("Hello World\n",t1->getOrginalContent());


}
TEST(fileInputClassTest, fullTest){
    FileInput f1("test.txt");
    DeleteChar d1;
    std::string data = f1.getData();
    f1.setOriginalContent(data);
    ASSERT_EQ("T\ne\ns\nt\n",f1.getOrginalContent());
    std::string processed = d1.deleteChar(data,'s');
    f1.setProcessedContent(processed);
    ASSERT_EQ("T\ne\n_\nt\n",f1.getProcessesContent());
    EXPECT_NE(f1.getOrginalContent(),f1.getProcessesContent());

}

TEST(stdinInputTest, VirtaulGetDataTestSingleLineTest){

    std::unique_ptr<Input> t1 = std::make_unique<StdinInput>();
    EXPECT_EQ("T est\ne s t\ns t\n\n\n",t1->getData());
}


int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();




}
