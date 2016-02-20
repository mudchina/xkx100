// Room: /d/suzhou/majiu.c
// Date: May,31 1998 Java

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是北大街的马厩，常年供应新鲜草料。苏州民风淳朴，马夫们会
把马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺
候到客人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "suzhou");
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_clean_up", 0);
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      扬州城:  rideyz

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"beidajie1",
		"south" : __DIR__"xiyuan",
		"up"    : SHOP_DIR"suzhou_shop",
	]));
	set("coor/x", 840);
	set("coor/y", -990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
