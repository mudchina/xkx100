//Room: /d/dali/majiu.c
//Date: June. 29 1998 by Java

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是军营边上的马厩，常年供应新鲜草料。据说此地民风淳朴，
客人只要带马来，马夫们就会把马牵到马厩好生照看，将它们喂饱饮
足，再洗刷得干乾净净。一直伺候到客人离城上路。马厩雨檐下的烂
木柱上钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "dali");
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

前往      成都城:  ridecd

TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"bingying",
		"up"   : SHOP_DIR"dali_shop",
	]));
	set("coor/x", -41010);
	set("coor/y", -71040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
