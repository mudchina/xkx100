// Room: /yangzhou/qingkongge.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","晴空阁");
	set("long",@LONG
晴空阁本名“真赏楼”，取欧阳修“遥知为我留真赏”句义。后由
户部员外郎孔尚任改题“晴空阁”，取欧阳修“平山栏槛倚晴空”句。
阁前有一小院落，两侧有廊，院中有四株古松柏，两廊枋上悬木鱼和云
板。廊中辟有一门，上悬“方丈”匾额。院北为四松草堂。
LONG );
	set("exits", ([
		"west"  : __DIR__"daxiongbaodian",
		"south" : __DIR__"pingyuanlou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}