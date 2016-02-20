//Room: shijie2.c 石阶
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","石阶");
      set("long",@LONG
你走在一条坚实的石阶上，不时地有进香客从你的身边走过。一边
是峭壁，一边是悬崖，抬头隐约可见笼罩在云雾中的天柱峰，听着流水
淙淙，令人心旷神怡。北边是一座牌坊。
LONG);
      set("objects", ([
          __DIR__"npc/guest" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"shibapan",
          "southup"    : __DIR__"zixiaogate",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -890);
	set("coor/z", 70);
	setup();
      replace_program(ROOM);
}
