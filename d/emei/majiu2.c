//Room: majiu2.c 马厩
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是草棚边的马厩，常年供应新鲜草料。据说此地民风淳朴，马夫们会把
马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到客人
上路。马厩中堆放著几堆草料，正中有一口泔槽。
	马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
LONG);
	set("outdoors", "emei");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/d/city/npc/camel": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往	峨嵋山脚: rideem

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"huayanding",
	]));
	set("no_clean_up", 0);
	set("coor/x", -6180);
	set("coor/y", -1070);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
