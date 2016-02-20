//Room: hcaeast.c 华藏庵侧殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","华藏庵侧殿");
      set("long",@LONG
这里是金顶华藏庵东侧殿，是接待香客及来宾的地方。殿内摆着几张桌子，
桌旁围放数把椅子。墙上悬着几幅字画，墙边一排书架，架上摆满经书。有几
位进香客正在品茶养神，欣赏墙上的字画或翻阅架上的经书。还有两个二十来
岁的姑娘在向一位师太打听有关出家的事。一个十来岁的小师太正在忙前忙后
招待客人。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/he" : 1,
           CLASS_D("emei") + "/wenhui" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "west"   : __DIR__"hcazhengdian", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6190);
	set("coor/y", -1160);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}