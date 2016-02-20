// /kaifeng/fangzhang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "方丈室");
	set("long", @LONG
方丈室内的陈设相对来说比较简单，正中的墙面上写着个大大的『
佛』字。地上铺着一张大席子，一张矮几就放在席子中间。两边是两个
锦垫。在靠里面的地方，有个蒲团，边上是个小木鱼，据说方丈大师每
天只需打坐片刻就精力充沛。
LONG);
	set("exits", ([
		"south" : __DIR__"xiaoyuan",
	]));
	set("objects", ([
		__DIR__"npc/zhiqing" : 1,
	]));

	setup();
	replace_program(ROOM);
}
