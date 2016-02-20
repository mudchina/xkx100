//Room: hcahoudian.c 华藏庵后殿
//Date: Oct. 2 1997 by That

inherit ROOM;
void do_chat();

void create()
{
      set("short","华藏庵后殿");
      set("long",@LONG
这是峨嵋山华藏庵的后殿。是峨嵋派掌门人传教弟子功夫的地方。这里
供有一尊普贤菩萨像。两旁靠墙放着几张太师椅，地上放着几个蒲团。掌门
人正在向几个女弟子传授武功。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/miejue" : 1,
      ]));
      set("no_get_from", 1);
      set("no_get", 1);
      set("no_steal", 1);
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
          "north" : __DIR__"hcadadian", 
          "out"   : __DIR__"yhrkou", 
      ]));
	set("coor/x", -6200);
	set("coor/y", -1190);
	set("coor/z", 200);
	setup();
      replace_program(ROOM);
}