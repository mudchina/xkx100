// Room: /d/wuxi/road16.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山道");
	set("long", @LONG
大驿道至此开始上山，四周看去群山环绕，但是却都是一些低矮
起伏的丘陵。山上覆盖着的都是青绿如一的丛林，纵眼望去，了无人
烟，远远依稀闻听鸟鸣兽啸。
LONG );
	set("outdoors", "yixing");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"  : __DIR__"road17",
		"east"     : __DIR__"road14",
	]));
	set("coor/x", 250);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
