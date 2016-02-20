//Room: majiu1.c 马厩
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是天外天客店后的马厩，常年供应新鲜草料。杭州自古号称天堂，
杭州的客店汇集四海宾客。马夫们会把马牵到马厩好生照看，将它们喂饱
饮足，再洗刷得干乾净净，一直伺候到客人上路。马厩雨檐下的烂木柱上
钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往	扬州城:  rideyz


TEXT]));
	set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"kedian",
		"up"   : SHOP_DIR"hangzhou_shop",
	]));
	set("no_clean_up", 0);
	set("coor/x", 4170);
	set("coor/y", -1480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
