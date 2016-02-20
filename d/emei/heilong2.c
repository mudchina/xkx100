//Room: heilong2.c 黑龙江栈道
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","黑龙江栈道");
      set("long",@LONG
黑龙江栈道沿黑龙江而建。这里一山中开，两崖并立，形成一道宽仅数尺，
长达几百米的深峡——白云峡。黑龙江栈道就从狭窄的白云峡中转折穿过，架
设在绝壁上。走在栈道上，只觉道窄人危；俯视深涧，急流飞旋，山静而觉动；
仰观头顶，天光如隙，崖开而欲合。这就是天开画图的「一线天」。栈道南通
千佛庵，北至清音阁。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"    : __DIR__"qianfoan",
          "north"    : __DIR__"heilong1",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/gancao" : random(2),
      ]));
	set("coor/x", -6130);
	set("coor/y", -1050);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}