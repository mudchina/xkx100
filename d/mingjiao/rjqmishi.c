//RJQMISHI.C

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是一间秘室，石壁之上嵌入两盏油灯，火苗幽蓝，石室地板用
精钢铸就，中央有一巨大铁炉，似乎也与地板铸为一体。炉中火苗熊熊，
烈炎冲天。几个壮士正在打造什么兵器，地上的打铁声就是从这里传出
的。石室角落中有一扇小铁门(men).
LONG );
	set("exits", ([
		"south" : __DIR__"rjqjiguan",
		"down"  : __DIR__"rjqmenlou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 860);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}