// Room: /d/yanziwu/path18.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "水边小路");
	set("long", @LONG
你走在湖边的小路上。西面几尺外的灌木丛外，就是太湖水了。湖
水常常淹没灌木丛，游鱼、水鸟争嬉猎食，溅起水花阵阵。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"ouxiang1",
		"southeast" : __DIR__"qingfeng",
	]));
	set("coor/x", 1190);
	set("coor/y", -1240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}