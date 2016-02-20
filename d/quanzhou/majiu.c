// Room: /d/quanzhou/majiu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "马厩");
	set("long", @LONG
这是客栈边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客
人只要住店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再
洗刷得干乾净净。一直伺候到客人离店上路。马厩中堆放著几堆草料，
正中有一口泔槽。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
LONG );
	set("outdoors", "quanzhou");
	set("item_desc", ([
		"paizi" :
"客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      福州城:  ridefz
"
	]));
	set("exits", ([
		"south" : __DIR__"kedian",
		"up"    : SHOP_DIR"quanzhou_shop",
	]));
	set("objects", ([
		"/clone/misc/mafu" : 1,
		"/d/city/npc/ziliuma" : 1,
		"/d/city/npc/zaohongma" : 1,
		"/d/city/npc/huangbiaoma" : 1,
	]));
	set("coor/x", 1860);
	set("coor/y", -6510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
