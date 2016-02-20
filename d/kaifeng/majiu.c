// /kaifeng/majiu.c
// Last modified by winder 2003.10.20

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "马厩");
	set("long", @LONG
这是稻香居后的马厩，常年供应新鲜草料。开封府自古乃军事重地，
历史悠久，民风淳朴。马夫们会把马牵到马厩好生照看，将它们喂饱饮
足，再洗刷得干乾净净，一直伺候到客人上路。马厩雨檐下的烂木柱上
钉着一块破木牌 (paizi)。马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
	set("outdoors", "kaifeng");
	set("no_fight", "1");
	set("no_beg", "1");
	set("objects", ([
		"/d/city/npc/zaohongma": 1,
		"/d/city/npc/huangbiaoma": 1,
		"/d/city/npc/ziliuma": 1,
		"/clone/misc/mafu": 1,
	]));
	set("exits",([
		"west" : __DIR__"daoxiang1",
		"up"   : SHOP_DIR"kaifeng_shop",
	]));
	set("item_desc", ([
		"paizi": @TEXT
客人们只要给马夫一两白银的租金就可以雇到一匹马了。

前往      扬州城:  rideyz
TEXT]));
	setup();
	replace_program(ROOM);
}
