// Room: /d/yanziwu/hongxia.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"红霞一楼"NOR);
	set("long", @LONG
这是一座很别致的小楼。楼檐下一块匾额上写着“红霞楼”三个粉
红篆字，楼下前后左右种的都是茶花。“滇中茶花记”载：“大理茶花
最甲海内，种类七十有二，大于牡丹，一望若火齐云锦，烁日蒸霞。”
云锦楼和红霞楼均是庄主人爱人及花所建。
LONG );
	set("exits", ([
		"south"    : __DIR__"path7",
		"north"    : __DIR__"path15",
		"eastdown" : __DIR__"huafang",
		"up"       : __DIR__"hongxia2",
	]));
	set("objects", ([
		__DIR__"obj/chahua13" : 1,
	]));
	set("coor/x", 1250);
	set("coor/y", -1250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}