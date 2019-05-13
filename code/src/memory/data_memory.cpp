/*
 * data_memory.cpp
 *
 *  Created on: May 10, 2019
 *      Author: albin
 */

#include "../../include/memory/data_memory.hpp"

void DataMemory::dmem1(
		bool            we,
		uint32_t        index,
		vector<uint8_t> write_value,
		vector<uint8_t> &read_value)
{
	FILE    *fp;
	char     ch;

	string   mem_url;
	string   memstr;
	string   all_memstr = "";
	string   hex_str;
	uint32_t cont = 0;

	int32_t  mem_value;

    uint32_t mask1 = 0b00000000000000000000000011111111;
    uint32_t mask2 = 0b00000000000000001111111100000000;
    uint32_t mask3 = 0b00000000111111110000000000000000;
    uint32_t mask4 = 0b11111111000000000000000000000000;

    stringstream sstream0,sstream1,sstream2, sstream3;
    sstream3 << hex << write_value[3];
    sstream2 << hex << write_value[2];
    sstream1 << hex << write_value[1];
    sstream0 << hex << write_value[0];
    string result = '\n' + sstream3.str() + sstream2.str() +sstream1.str() +
    		sstream0.str();

    mem_url = "/home/albin/vector_arquitecture/code/src/memory/"
    		"memfile1.dat";

    fp = fopen(mem_url.c_str(), "r"); // read mode

    if (fp == NULL)
    {
    	perror("Error while opening the file.\n");
    	exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF){

    	if(ch == '\n') cont++;

    	if(index == cont) {
    		memstr += ch;
    		all_memstr +=  result;
    		result = "";
    	} else all_memstr += ch;
    }

    fclose(fp);

    mem_value = (int)stoul(memstr.c_str(),nullptr,16);

    uint8_t out1 = (mem_value & mask1);
    uint8_t out2 = (mem_value & mask2) >> 8;
    uint8_t out3 = (mem_value & mask3) >> 16;
    uint8_t out4 = (mem_value & mask4) >> 24;

    read_value[0] = out1;
    read_value[1] = out2;
    read_value[2] = out3;
    read_value[3] = out4;

    if(we){
    	fp = fopen(mem_url.c_str(), "w"); // read mode
    	fwrite (all_memstr.c_str() , sizeof(char), sizeof(all_memstr)*100000000000, fp);
    	fclose(fp);
    }
}

void DataMemory::dmem2(
		bool            we,
		uint32_t        index,
		vector<uint8_t> write_value,
		vector<uint8_t> &read_value)
{
	FILE    *fp;
	char     ch;

	string   mem_url;
	string   memstr;
	string   all_memstr = "";
	string   hex_str;
	uint32_t cont = 0;

	int32_t  mem_value;

    uint32_t mask1 = 0b00000000000000000000000011111111;
    uint32_t mask2 = 0b00000000000000001111111100000000;
    uint32_t mask3 = 0b00000000111111110000000000000000;
    uint32_t mask4 = 0b11111111000000000000000000000000;

    stringstream sstream0,sstream1,sstream2, sstream3;
    sstream3 << hex << write_value[3];
    sstream2 << hex << write_value[2];
    sstream1 << hex << write_value[1];
    sstream0 << hex << write_value[0];
    string result = '\n' + sstream3.str() + sstream2.str() +sstream1.str() +
    		sstream0.str();

    mem_url = "/home/albin/vector_arquitecture/code/src/memory/"
    		"memfile2.dat";

    fp = fopen(mem_url.c_str(), "r"); // read mode

    if (fp == NULL)
    {
    	perror("Error while opening the file.\n");
    	exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF){

    	if(ch == '\n') cont++;

    	if(index == cont) {
    		memstr += ch;
    		all_memstr +=  result;
    		result = "";
    	} else all_memstr += ch;
    }

    fclose(fp);

    mem_value = (int)stoul(memstr.c_str(),nullptr,16);

    uint8_t out1 = (mem_value & mask1);
    uint8_t out2 = (mem_value & mask2) >> 8;
    uint8_t out3 = (mem_value & mask3) >> 16;
    uint8_t out4 = (mem_value & mask4) >> 24;

    read_value[0] = out1;
    read_value[1] = out2;
    read_value[2] = out3;
    read_value[3] = out4;

    if(we){
    	fp = fopen(mem_url.c_str(), "w"); // read mode
    	fwrite (all_memstr.c_str() , sizeof(char), sizeof(all_memstr)*100000000000, fp);
    	fclose(fp);
    }
}

void DataMemory::dmem3(
		bool            we,
		uint32_t        index,
		vector<uint8_t> write_value,
		vector<uint8_t> &read_value)
{
	FILE    *fp;
	char     ch;

	string   mem_url;
	string   memstr;
	string   all_memstr = "";
	string   hex_str;
	uint32_t cont = 0;

	int32_t  mem_value;

    uint32_t mask1 = 0b00000000000000000000000011111111;
    uint32_t mask2 = 0b00000000000000001111111100000000;
    uint32_t mask3 = 0b00000000111111110000000000000000;
    uint32_t mask4 = 0b11111111000000000000000000000000;

    stringstream sstream0,sstream1,sstream2, sstream3;
    sstream3 << hex << write_value[3];
    sstream2 << hex << write_value[2];
    sstream1 << hex << write_value[1];
    sstream0 << hex << write_value[0];
    string result = '\n' + sstream3.str() + sstream2.str() +sstream1.str() +
    		sstream0.str();

    mem_url = "/home/albin/vector_arquitecture/code/src/memory/"
    		"memfile3.dat";

    fp = fopen(mem_url.c_str(), "r"); // read mode

    if (fp == NULL)
    {
    	perror("Error while opening the file.\n");
    	exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF){

    	if(ch == '\n') cont++;

    	if(index == cont) {
    		memstr += ch;
    		all_memstr +=  result;
    		result = "";
    	} else all_memstr += ch;
    }

    fclose(fp);

    mem_value = (int)stoul(memstr.c_str(),nullptr,16);

    uint8_t out1 = (mem_value & mask1);
    uint8_t out2 = (mem_value & mask2) >> 8;
    uint8_t out3 = (mem_value & mask3) >> 16;
    uint8_t out4 = (mem_value & mask4) >> 24;

    read_value[0] = out1;
    read_value[1] = out2;
    read_value[2] = out3;
    read_value[3] = out4;

    if(we){
    	fp = fopen(mem_url.c_str(), "w"); // read mode
    	fwrite (all_memstr.c_str() , sizeof(char), sizeof(all_memstr)*100000000000, fp);
    	fclose(fp);
    }
}

void DataMemory::dmem4(
		bool            we,
		uint32_t        index,
		vector<uint8_t> write_value,
		vector<uint8_t> &read_value)
{
	FILE    *fp;
	char     ch;

	string   mem_url;
	string   memstr;
	string   all_memstr = "";
	string   hex_str;
	uint32_t cont = 0;

	int32_t  mem_value;

    uint32_t mask1 = 0b00000000000000000000000011111111;
    uint32_t mask2 = 0b00000000000000001111111100000000;
    uint32_t mask3 = 0b00000000111111110000000000000000;
    uint32_t mask4 = 0b11111111000000000000000000000000;

    stringstream sstream0,sstream1,sstream2, sstream3;
    sstream3 << hex << write_value[3];
    sstream2 << hex << write_value[2];
    sstream1 << hex << write_value[1];
    sstream0 << hex << write_value[0];
    string result = '\n' + sstream3.str() + sstream2.str() +sstream1.str() +
    		sstream0.str();

    mem_url = "/home/albin/vector_arquitecture/code/src/memory/"
    		"memfile4.dat";

    fp = fopen(mem_url.c_str(), "r"); // read mode

    if (fp == NULL)
    {
    	perror("Error while opening the file.\n");
    	exit(EXIT_FAILURE);
    }

    while((ch = fgetc(fp)) != EOF){

    	if(ch == '\n') cont++;

    	if(index == cont) {
    		memstr += ch;
    		all_memstr +=  result;
    		result = "";
    	} else all_memstr += ch;
    }

    fclose(fp);

    mem_value = (int)stoul(memstr.c_str(),nullptr,16);

    uint8_t out1 = (mem_value & mask1);
    uint8_t out2 = (mem_value & mask2) >> 8;
    uint8_t out3 = (mem_value & mask3) >> 16;
    uint8_t out4 = (mem_value & mask4) >> 24;

    read_value[0] = out1;
    read_value[1] = out2;
    read_value[2] = out3;
    read_value[3] = out4;

    if(we){
    	fp = fopen(mem_url.c_str(), "w"); // read mode
    	fwrite (all_memstr.c_str() , sizeof(char), sizeof(all_memstr)*100000000000, fp);
    	fclose(fp);
    }
}




