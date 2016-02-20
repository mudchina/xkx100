// /kaifeng/caifang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这间小柴房堆满了松柴，多是卖柴的汉子因为卖不出去而拿来换上
一餐的。也有些是穷苦人上山砍了奉献给佛祖的，好在开封边的野猪林
多的是松树，所以倒也从没缺过柴禾。
LONG);

	set("objects", ([
		__DIR__"npc/obj/chaihe1" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"zoulang2",
		"east" : __DIR__"caidi3",
	]));

	setup();
	replace_program(ROOM);
}
