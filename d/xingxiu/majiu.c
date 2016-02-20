//Room: majiu1.c 马厩
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是北疆小镇的马厩，常年供应新鲜草料。这里地处会疆，边民古
朴而好客，把所有远方来宾均作兄弟看待。马夫们会把马牵到马厩好生
照看，将它们喂饱饮足，再梳理得清清爽爽，一直伺候到客人上路。马
厩旧木柱上钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
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

前往      长安城:  rideca


TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"kezhan",
//		"up"   : SHOP_DIR"yili_shop",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38990);
	set("coor/y", 13100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
