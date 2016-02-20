//Room: majiu.c 马厩
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short","马厩");
	set("long",@LONG
这是客栈边上的马厩，常年供应新鲜草料。据说此地民风淳朴，客
人只要住店，马夫们就会把马牵到马厩好生照看，将它们喂饱饮足，再
洗刷得干乾净净。一直伺候到客人离店上路。马厩中堆放著几堆草料，
正中有一口泔槽。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
LONG);
	set("outdoors", "yongdeng");
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
          灵州城:  ridelz

TEXT]));
	set("exits",([ /* sizeof() == 1 */
	    "east"      : __DIR__"kedian",
	]));
	set("coor/x", -9620);
	set("coor/y", 3100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
