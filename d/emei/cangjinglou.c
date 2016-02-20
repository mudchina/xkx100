//Room: cangjinglou.c 藏经楼
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","藏经楼");
      set("long",@LONG
这里是报国寺的藏经楼。阁楼上密密麻麻排了好多书架，架上摆满了经书。
有两个身穿白衣的小师太正在一角静静地读着经书。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/daoming" : 1,
           __DIR__"obj/fojing1"+random(2) : 1,
           __DIR__"obj/fojing2"+random(2) : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "south"    : __DIR__"dxdian",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6020);
	set("coor/y", -1010);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
     if ((dir == "south") && ( present("shu", me))
          && objectp(present("daoming", environment(me))))
     {
         return notify_fail
                ("道明小师父见你想把经书拿走，上前轻声说道：本阁经书不外借。\n");
     }
     return ::valid_leave(me, dir);
}