// Room: /city/lichunyuan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "丽春院");
	set("long", @LONG
你一走进来，一眼就看到大厅的墙上挂着一幅幅春宫图(tu)，一下
子就明白了这是什么地方。厅内到处张灯结彩，香气扑鼻。几名打扮得
妖里妖气的女人分站两旁对你发出媚笑。主人韦春芳上上下下、前前后
后招呼着客人。从楼上传来了阵阵打情骂俏的声音。
LONG );
	set("objects", ([
                CLASS_D("gaibang") + "/kongkong" : 1,
                __DIR__"npc/wei" : 1,
                "/d/beijing/npc/mao18" : 1, 
	]));

	set("item_desc", ([
		"tu" :
"                                      Ο        Ο          Ο             
                                    ┌│        │          │
      ┌—Ο┌—  —┬——Ο        │┤      ┌┘          └┐
    —┘Ο—┘    ————Ο  Ο——┘│  Ο—┼┴—  Ο——┴┼


   Ο       Ο    ΟΟΟ                 Ο                  ○
   │       │    │├┼       ┌—Ο  ┌┼                  │
   ├ Ο┬┐┤    ├└┼┐   —┘Ο——┘┤          ○┬—┐┤
   │   ┘└│    │  │                 └            │  ││
	\n"]));
	set("exits", ([
		"east"  : __DIR__"beiliuxiang",
		"up"    : __DIR__"lichunyuan2",
	]));

	set("coor/x", 30);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
