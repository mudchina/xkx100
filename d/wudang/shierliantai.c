//Room: shierliantai.c 十二莲台
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","十二莲台");
      set("long",@LONG
这里是武当绝顶的十二莲台，台与台之间以曲栏相连，雕刻精美，
是远眺的最佳所在。站立此台四眺，宛如身在千叶宝莲之上，千峰万壑
都在脚下。往西可望到七百里外的华山，东望则汉水如练，襄、樊一带
尽收眼底。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east"     : __DIR__"jinding",
      ]));
      set("objects", ([
          "/clone/medicine/vegetable/huoxiang" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2040);
	set("coor/y", -1040);
	set("coor/z", 180);
	setup();
      replace_program(ROOM);
}
