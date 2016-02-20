//Room: wnachanfang.c 万年庵禅房
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","万年庵禅房");
      set("long",@LONG
这里是一间安静宽敞的禅房，乃是庵中弟子打坐修行之所。地下整整
齐齐地放着许多蒲团。几位年轻师太和俗家女弟子正肃容入定。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"wnadian",
      ]));
      set("sleep_room", 1);
      set("no_clean_up", 0);
      set("no_fight", 1);
	set("coor/x", -6120);
	set("coor/y", -1060);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}