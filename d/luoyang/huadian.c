// Room: /d/luoyang/huadian.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "花店");
	set("long",  @LONG
这是一家出售各种花卉的店铺，你被怡人的花香，多采的花姿所吸
引，信步踱入店中。老板娘能在这兵荒马乱的年头，保留这么一家花店
让人实在难以想象。店面上挂了个牌子(paizi)。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  :  __DIR__"southroad",
		"north" :  __DIR__"eastroad",
	]));
	set("item_desc",  ([
		"paizi" : "
送花服务： send <花草代号> to <玩家代号> \n",
	]));
	set("objects",  ([
		__DIR__"npc/laoban" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
