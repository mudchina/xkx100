//Room: shiliang.c 石梁
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","石梁");
      set("long",@LONG
你走入山坞中，有一道石梁跨溪而建，这里是九渡涧的下流，各岭
之水均在此交汇，景色极佳。附近设有许多小吃店，游人至此，大多小
住歇歇脚力。再往上就是陡峭的十八盘了。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northup"    : __DIR__"taizipo",
          "southup"    : __DIR__"shibapan",
          "east"       : __DIR__"shop",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/shengdi" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2050);
	set("coor/y", -870);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}
