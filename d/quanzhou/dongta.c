// Room: /d/quanzhou/dongta.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "东塔");
	set("long", @LONG
东塔又名镇国塔，完工于南宋淳佑十年，共耗时十二年。建塔时是
用堆土坡运石办法，逐级建筑上去的。它是一座浑体花岗石的仿木结构
的楼阁式建筑，平面八方，五层五楼，颇为少见。塔座作须弥作形，塔
檐高翘，呈弯弧状向外舒展。塔每层开四门设四龛，门外均伸出平座勾
栏。塔顶高托沃金铜葫芦，映日闪闪发光。八条铁链从塔顶上斜系于八
个角脊(jiaoji)。塔每层的门龛两旁有武士、天王、金刚、罗汉等浮雕
计八十尊，神态各异。东塔须弥座束腰部分还有三十九幅难得一见的青
石浮雕佛传图。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("item_desc", ([
		"jiaoji" : "每个角脊下还悬挂着小铜钟，全塔共四十个，风一吹便叮当作响。\n",
	]));
	set("exits", ([
		"west"   : __DIR__"yuetai",
	]));
	set("coor/x", 1840);
	set("coor/y", -6490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
