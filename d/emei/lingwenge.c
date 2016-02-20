//Room: lingwenge.c 灵文阁
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","灵文阁");
      set("long",@LONG
这里是福寿庵的灵文阁，是主持静照师太传授佛法的地方。两名青衣小尼
随侍在旁，似乎在聆听师太的教晦。阁内布置简陋，靠墙放着几把竹椅，地上
放着几个蒲团。东首有一禅房。西面是一个斋厅。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/zhao" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"     : __DIR__"fushouan",
          "east"    : __DIR__"fsachanfang",
          "west"    : __DIR__"fsazhaitang",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6100);
	set("coor/y", -1060);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}