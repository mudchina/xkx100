// Room: /d/taishan/bixia.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "碧霞祠");
	set("long", @LONG
这是一座历史悠久而宏伟壮丽的祠院。相传它建于唐代以前，宋、
元、明、清各代均曾增建。祠院设有东西两殿，分别称为东西宝库，储
存着进香客的捐施，两殿的屋瓦都是由铁铸成。从四方八面来泰山上香
的男女，都是先到碧霞祠，然后才到其他的庙宇。从这里往东南走便可
到达宝藏岭。
LONG );
	set("exits", ([
		"west"      : __DIR__"yunuchi",
		"westup"    : __DIR__"weiping",
		"southeast" : __DIR__"baozang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 770);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
