//Room: jinding.c 金顶
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","金顶");
      set("long",@LONG
这就是峨嵋山的主峰金顶了。此峰耸立大地，高入云表，秀丽而又壮美，
李白赞颂它：『青冥倚天开，彩错疑画出。』登上金顶，视野豁然开朗，鸟瞰
脚下，但见群峰涌绿叠翠，三江如丝如带；回首远眺，则见大雪山横亘天际，
贡嘎山直插苍穹。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"wanxingan",
          "southwest"  : __DIR__"woyunan", 
          "south"      : __DIR__"huacangan",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6220);
	set("coor/y", -1140);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}