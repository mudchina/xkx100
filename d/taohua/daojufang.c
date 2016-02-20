inherit ROOM;

void create()
{
	set("short", "道具房");
	set("long", @LONG
这是一间道具房。摆着一些桃花弟子们常用的东西。房里好象黑
乎乎的，靠窗处有一张斑驳长桌和一把靠背椅，虽是白天还点着小油
灯。哑仆看到你进来，就使劲瞪着你，虽然口不能言，可你还是心中
惴惴。
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang3",
	]));
	set("objects", ([
		__DIR__"obj/xiang" : 1,
	]) );
	set("coor/x", 8990);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}