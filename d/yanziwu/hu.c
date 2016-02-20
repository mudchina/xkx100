// Room: /d/yanziwu/hu.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "百曲湖");
	set("long",@LONG
这是一个支流众多的小河，四面都是菱叶。除了桨声和菱叶与船身
相擦的沙沙轻声，四下一片寂静，湖上清风，夹着淡淡的花香，你不禁
心想：“就算这样一辈子，也好哇！”
LONG );
	set("outdoors", "yanziwu");
	set("no_clean_up", 0);
	set("coor/x", 1300);
	set("coor/y", -1820);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
