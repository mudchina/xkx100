// Room: /binghuo/zhou.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "小舟");
	set("long", @LONG
碧纱灯笼照映下，一位妙龄丽人端坐舟头，手白胜雪，玉颊微瘦，
眉弯鼻挺，一笑时左颊上浅浅一个梨涡。只听得琴韵冷冷，那个少女
正在抚琴。
LONG );
	set("outdoors", "binghuo");
	set("exits", ([
		"out" : __DIR__"qiantang",
	]));
	set("objects", ([
		"/d/mingjiao/npc/yinsusu" : 1,
	]));
	setup();
}
