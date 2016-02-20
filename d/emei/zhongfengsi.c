//Room: zhongfengsi.c 中峰寺
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","中峰寺");
      set("long",@LONG
中峰寺在白云峰下，始建于晋代，原为道观。传说观内的道人每年在三月
三日都献身给山中一条大蟒，以为可以升仙。后来有个从资州来的明果禅师，
杀了那条大蟒，道士们始知上当，感激不已，自愿改信佛教，从此改观为寺。
这里往北可到清音阁，东下至神水庵。
LONG);
      set("objects", ([
               __DIR__+"npc/guest": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northwest"    : __DIR__"qingyinge",
          "eastdown"     : __DIR__"shenshuian",
      ]));
      set("outdoors", "emei");
//      set("no_clean_up", 0);
	set("coor/x", -6110);
	set("coor/y", -1040);
	set("coor/z", 80);
	setup();
      replace_program(ROOM);
}