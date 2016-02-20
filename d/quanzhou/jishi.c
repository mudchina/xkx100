// Room: /d/quanzhou/jishi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "集市");
	set("long", @LONG
这里是居民购买日常生活用品和商贩的场所，各种商品应有尽有，
琳琅满目。同时这里也进行着与外国商人的买卖交易。香料、石等是本
地商家最抢手的需求品，因为他们都知道一旦将其运到中原，将会获得
极丰厚的利润。不难想象为何这里长年累月人来人往，川流不息，吵吵
嚷嚷尽是讨价还价的声音。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"huajiaoting",
		"east"  : __DIR__"tumenji",
		"west"  : __DIR__"xinmenji",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
