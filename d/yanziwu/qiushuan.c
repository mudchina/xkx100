//ROOM: /d/yanziwu/qiushuan.c

inherit ROOM;

void create()
{
	set("short", "秋爽斋");
	set("long",@LONG
素幔低垂，设备朴素，临窗的桌上堆满卷轴，一大桶毛笔显示出主
人学识渊博。一只剑形花瓶插着几朵犁花，带来几分清新的气息。
LONG );
	set("exits", ([
		"east" : __DIR__"canheju",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}