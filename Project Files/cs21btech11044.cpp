// Disassembler : 
#include <iostream>
#include<math.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int Bin2DecSigned(string Bin){
    int decimal = 0;

    if(Bin[0] == '1'){

        for(int i=0;i<Bin.length();i++){
        if(Bin[Bin.length()-i-1] == '1'){
            decimal = decimal + pow(2,i);
            }
        }
        decimal = decimal - pow(2,Bin.length());
    }
    else{
        for(int i=0;i<Bin.length();i++){
        if(Bin[Bin.length()-i-1] == '1'){
            decimal = decimal + pow(2,i);
            }
        }
    }

    return decimal;
}

int Bin2Dec(string Bin){
    int decimal = 0;

    for(int i=0;i<Bin.length();i++){
        if(Bin[Bin.length()-i-1] == '1'){
            decimal = decimal + pow(2,i);
        }
    }

    return decimal;
}

string Hex2Bin(string hex){

string Bin;
char bit;

    for(int i=0;i<8;i++){

        bit = hex[i];

        switch(bit){
            case '0':
            Bin = Bin + "0000";
            break;
            case '1':
            Bin = Bin + "0001";
            break;
            case '2':
            Bin = Bin + "0010";
            break;
            case '3':
            Bin = Bin + "0011";
            break;
            case '4':
            Bin = Bin + "0100";
            break;
            case '5':
            Bin = Bin + "0101";
            break;
            case '6':
            Bin = Bin + "0110";
            break;
            case '7':
            Bin = Bin + "0111";
            break;
            case '8':
            Bin = Bin + "1000";
            break;
            case '9':
            Bin = Bin + "1001";
            break;
            case 'a':
            Bin = Bin + "1010";
            break;
            case 'b':
            Bin = Bin + "1011";
            break;
            case 'c':
            Bin = Bin + "1100";
            break;
            case 'd':
            Bin = Bin + "1101";
            break;
            case 'e':
            Bin = Bin + "1110";
            break;
            case 'f':
            Bin = Bin + "1111";
            break;
        }

    }
return Bin;
}

string subString(int start,int end,string main){
    
    char sub[end - start + 1];
    int a=0; // track., used to add elements to SUBSTRING from main string.

    for(int i=start;i<=end;i++){
        sub[a] = main[i];
        a++;
    }   

    string subString;
    subString = sub;

return subString;
}

void Utype(string main,string hex){

    string imm_12_31,rd;

    rd = main.substr(20,5);
    imm_12_31 = hex.substr(0,5);
    cout<<"lui x"<<Bin2Dec(rd)<<", 0x"<<imm_12_31<<endl;

    return;
}


void I3type(string main){
    string rd,func3,rs1,imm,func6;

    func3 = main.substr(17,3);//subString(17,19,main);
    rd = main.substr(20,5);//subString(20,24,main);
    rs1 = main.substr(12,5);//subString(12,16,main);
    imm = main.substr(0,12);//subString(0,11,main);

    if(func3 == "000"){
        cout<<"jalr x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", "<<Bin2DecSigned(imm)<<endl;
    }
    else{
        cout<<"Invalid operation"<<endl;
    }


    return;
}

void Jtype(string main){

    string imm_20,imm_10_1,imm_11,imm_19_12,rd,imm_0,imm;

    imm_20 = main.substr(0,1);//subString(0,0,main);
    imm_10_1 = main.substr(1,10);//subString(1,10,main);
    imm_11 = main.substr(11,1);//subString(11,11,main);
    imm_19_12 = main.substr(12,8);//subString(12,19,main);
    rd = main.substr(20,5);//subString(20,24,main);
    imm_0 = "0";
    imm = imm_20+imm_19_12+imm_11+imm_10_1+imm_0;

    cout<<"jal x"<<Bin2Dec(rd)<<", "<<Bin2DecSigned(imm)<<endl;

    return;
}

void Btype(string main){

    string imm_12,imm_10_5,rs2,rs1,func3,imm_4_1,imm_11,imm_0,imm;

    imm_12 = main.substr(0,1);//subString(0,0,main);
    imm_10_5 = main.substr(1,6);//subString(1,6,main);
    rs2 = main.substr(7,5);//subString(7,11,main);
    rs1 = main.substr(12,5);//subString(12,16,main);
    func3 = main.substr(17,3);//subString(17,19,main);
    imm_4_1 = main.substr(20,4);//subString(20,23,main);
    imm_11 = main.substr(24,1);//subString(24,24,main);
    imm_0 = "0";
    imm = imm_12 + imm_11 + imm_10_5 + imm_4_1 + imm_0;

    if(func3 == "000"){
        //beq
        cout<<"beq x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<" ,"<<Bin2DecSigned(imm)<<endl;
    }
    else if (func3 == "001"){
        //bne
        cout<<"bne x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<" ,"<<Bin2DecSigned(imm)<<endl;
    }
    else if(func3 == "100"){
        //blt
        cout<<"blt x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<" ,"<<Bin2DecSigned(imm)<<endl;
    }
    else if(func3 == "101"){
        //bge
        cout<<"bge x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<" ,"<<Bin2DecSigned(imm)<<endl;
    }
    else if(func3 == "110"){
        //bltu
        cout<<"bltu x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<" ,"<<Bin2DecSigned(imm)<<endl;
    }   
    else if(func3 == "111"){
        //bgeu
        cout<<"bgeu x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<" ,"<<Bin2DecSigned(imm)<<endl;
    }
    else{
        cout<<"Invalid Opearation"<<endl;
    }
    return;
}

// I considered n to be tot imm i.e (11:5 + 4:0) is that correct.
void Stype(string main){
    string imm_11_5 ,rs2,rs1,func3,imm_4_0,imm;

    imm_11_5 = main.substr(0,7);//subString(0,6,main);
    rs2 = main.substr(7,5);//subString(7,11,main);
    rs1 = main.substr(12,5);//subString(12,16,main);
    func3 = main.substr(17,3);//subString(17,19,main);
    imm_4_0 = main.substr(20,5);//subString(20,24,main);
    imm = imm_11_5 + imm_4_0;

    if(func3 == "000"){
        //sb
        cout<<"sb x"<<Bin2Dec(rs2)<<", "<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "001"){
        //sh
        cout<<"sh x"<<Bin2Dec(rs2)<<", "<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "010"){
        //sw
        cout<<"sw x"<<Bin2Dec(rs2)<<", "<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "011"){
        //sd
        cout<<"sd x"<<Bin2Dec(rs2)<<", "<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else{
        cout<<"Invalid Operation"<<endl;
    }
    return;
}

// what is the difference here in lw and lwu. (signed and unsigned).

void I2type(string main){
    string rd,func3,rs1,imm,func6;

    func3 = main.substr(17,3);//subString(17,19,main);
    rd = main.substr(20,5);//subString(20,24,main);
    rs1 = main.substr(12,5);//subString(12,16,main);
    imm = main.substr(0,12);//subString(0,11,main);

    if(func3 == "000"){
        //lb
        cout<<"lb x"<<Bin2Dec(rd)<<" ,"<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "001"){
        //lh
        cout<<"lh x"<<Bin2Dec(rd)<<" ,"<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "010"){
        //lw
        cout<<"lw x"<<Bin2Dec(rd)<<" ,"<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "011"){
        //ld
        cout<<"ld x"<<Bin2Dec(rd)<<" ,"<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "100"){
        //lbu
        cout<<"lbu x"<<Bin2Dec(rd)<<" ,"<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "101"){
        //lhu
        cout<<"lhu x"<<Bin2Dec(rd)<<" ,"<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else if(func3 == "110"){
        //lwu
        cout<<"lwu x"<<Bin2Dec(rd)<<" ,"<<Bin2DecSigned(imm)<<"(x"<<Bin2Dec(rs1)<<")"<<endl;
    }
    else{
        cout<<"Invalid Operation"<<endl;
    }
    return;
}

void I1type(string main){
    string rd,func3,rs1,imm,func6;

    func3 = main.substr(17,3);//subString(17,19,main);
    rd = main.substr(20,5);//subString(20,24,main);
    rs1 = main.substr(12,5);//subString(12,16,main);
    if((func3 == "001") || (func3 == "101")){ //func3 : 1(or)5; slli,srli,srai. 
    func6 = main.substr(0,6);//subString(0,5,main);
    imm = main.substr(6,6);//subString(6,11,main);
    }
    else{
    imm = main.substr(0,12);//subString(0,11,main);
    }

    if(func3 == "000"){
        //addi
        cout<<"addi x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", "<<Bin2DecSigned(imm)<<endl;
    }
    else if(func3 == "100"){
        //xori
        cout<<"xori x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", "<<Bin2DecSigned(imm)<<endl;
    }
    else if(func3 == "110"){
        //ori
        cout<<"ori x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", "<<Bin2DecSigned(imm)<<endl;
    }
    else if(func3 == "111"){
        //andi
        cout<<"andi x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", "<<Bin2DecSigned(imm)<<endl;
    }
    else if((func3 == "001") && (func6 == "000000")){
        //slli
        cout<<"slli x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", "<<Bin2DecSigned(imm)<<endl;
    }
    else if((func3 == "101") && (func6 == "000000")){
        //srli
        cout<<"srli x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", "<<Bin2DecSigned(imm)<<endl;
    }
    else if((func3 == "101") && (func6 == "010000")){
        //srai
        cout<<"srai x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", "<<Bin2DecSigned(imm)<<endl;
    }
    else{
        cout<<"invalid operation"<<endl;
    }

   return; 
}

void Rtype(string main){

    string func7,rs2,rs1,func3,rd;

    func7 = main.substr(0,7);//subString(0,6,main);
    rs2 = main.substr(7,5);//subString(7,11,main);
    rs1 = main.substr(12,5);//subString(12,16,main);
    func3 = main.substr(17,3);//subString(17,19,main);
    rd = main.substr(20,5);//subString(20,24,main);

    if((func3 == "000") && (func7 =="0000000")){
        //ADD.
        cout<<"add x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<endl;
    }
    else if((func3 == "000") && (func7 =="0100000")){
        //SUB.
        cout<<"sub x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<endl;
    }
    else if((func3 == "100") && (func7 =="0000000")){
        //XOR.
        cout<<"xor x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<endl;
    }
    else if((func3 == "110") && (func7 =="0000000")){
        //OR.
        cout<<"or x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<endl;
    }
    else if((func3 == "111") && (func7 =="0000000")){
        //AND.
        cout<<"and x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<endl;
    }
    else if((func3 == "001") && (func7 =="0000000")){
        //Shift left logical.
        cout<<"sll x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<endl;
    }
    else if((func3 == "101") && (func7 =="0000000")){
        //Shift Right logical.
        cout<<"srl x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<endl;
    }
    else if((func3 == "101") && (func7 =="0100000")){
        //Shift Right Arith.
        cout<<"sra x"<<Bin2Dec(rd)<<", x"<<Bin2Dec(rs1)<<", x"<<Bin2Dec(rs2)<<endl;
    }
    else{
        cout<<"Invalid operation"<<endl;
    }

    return;
}

void Disassembler(string hex){
    string main;
    main = Hex2Bin(hex);
    // this will further redirect to cat like: R,I,S,B,U.
    // find optcode for given binary code.
    string opcode;
    opcode = subString(25,31,main);

    if(opcode == "0110011"){ //R
        // cout<<opcode<<endl;
        Rtype(main);
    }
    else if(opcode == "0010011"){ //I 
        I1type(main);
    }
    else if(opcode == "0000011"){ //I: ld
        I2type(main);
    }
    else if(opcode == "0100011"){//S: sd
        Stype(main);
    }
    else if(opcode == "1100011"){//B : branch.
        Btype(main);
    }
    else if(opcode == "1101111"){//jump and link.
        Jtype(main);
    }
    else if(opcode == "1100111"){ //jump and link reg.
        I3type(main);
    }
    else if(opcode == "0110111"){// Load Upper Imm
        Utype(main,hex);
    }
    else{
       cout<<"Invalid Operation"<<endl;
    }
return;
}

int main(){

vector<string> hexcode; 
hexcode.push_back("01a10533");
hexcode.push_back("10005137");
hexcode.push_back("0004c5b3");
hexcode.push_back("00317833");
hexcode.push_back("00200d93");
hexcode.push_back("0011c383");
hexcode.push_back("ffbd4ae3");
hexcode.push_back("00221d93");
hexcode.push_back("005f8067");
hexcode.push_back("40325393");
hexcode.push_back("00711633");
hexcode.push_back("00525393");
hexcode.push_back("0051bd03");
hexcode.push_back("40130433");
hexcode.push_back("40715633");
hexcode.push_back("00113423");
hexcode.push_back("0051bd03");
hexcode.push_back("00a31423");
hexcode.push_back("00659263");
hexcode.push_back("02a00fef");


for(int i=0;i<hexcode.size();i++){
    Disassembler(hexcode[i]);
}

return 0;
}