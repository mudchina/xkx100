//Room: bailongdong.c 白龙洞
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","白龙洞");
      set("long",@LONG
白龙洞据说是《白蛇传》中的白娘子修炼成仙之处。这里楠木参天，林荫
夹道，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，传为古时一高僧按《法华
经》口诵一字，植树一株，共植六万九千七百七十七株，时称古德林。这里北
上至万年庵，南下是清音阁。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"gudelin1",
          "west"      : __DIR__"gudelin2",
          "northup"   : __DIR__"wannianan",
          "southeast" : __DIR__"qingyinge",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6130);
	set("coor/y", -1070);
	set("coor/z", 50);
	setup();
      replace_program(ROOM);
}