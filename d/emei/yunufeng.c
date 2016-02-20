//Room: yunufeng.c 玉女峰
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","玉女峰");
      set("long",@LONG
这是归云阁边的玉女峰，峰顶有一个四尺见方的小池，深亦四尺，四季不
枯，传为天女沐浴之器。古时州刺史冯楫，曾在此结茅而居，发奋诵读《华严
经》，不食人间烟火，于是玉女下凡，为他馈赠食物。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/fang" : 1,
           "/clone/medicine/vegetable/fangfeng" : random(2),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"guiyunge",
      ]));
      set("outdoors", "emei");
	set("coor/x", -6080);
	set("coor/y", -1050);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}