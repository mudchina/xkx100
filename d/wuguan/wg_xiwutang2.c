// wg_xiwutang2.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "习武堂");
	set("long", @LONG
扬州武馆是专为初出江湖的少年设立的。由于江湖叛师是十分为人
不齿的，初出道的少年可以在此学习一些基本的防身武功，一来不会光
阴虚度，二来也好为今后选定一个心慕的门派。
    墙上贴着个贴子(tiezi)。
LONG );
	set("item_desc", ([
		"tiezi" : @TEXT
扬州武馆敬启者：不须把所有的基本武功学全。必要的基本武功是：

㈠ 基本内功
㈡ 基本轻功
㈢ 基本招架
㈣ 基本拳脚：基本拳脚、基本手法、基本掌法、基本指法、基本拳法、
             基本爪法、基本腿法任选几种。
㈤ 基本兵器：基本刀法、基本枪法、基本剑法、基本棍法、基本棒法、
             基本杖法、基本斧法、基本刺法、基本锤法、基本钩法、
             基本鞭法、基本暗器任选几种。

─────────────────────────────
「扬州武馆」所传授基本武功
─────────────────────────────
  １）基本内功 (force)            １２）基本枪法 (spear)
  ２）基本轻功 (dodge)            １３）基本剑法 (sword)
  ３）基本招架 (parry)            １４）基本棍法 (club)
  ４）基本拳脚 (unarmed)          １５）基本棒法 (stick)
  ５）基本手法 (hand)             １６）基本杖法 (staff)
  ６）基本掌法 (strike)           １７）基本斧法 (axe)
  ７）基本指法 (finger)           １８）基本刺法 (dagger)
  ８）基本拳法 (cuff)             １９）基本锤法 (hammer)
  ９）基本爪法 (claw)             ２０）基本钩法 (hook)
１０）基本腿法 (leg)              ２１）基本鞭法 (whip)
１１）基本刀法 (blade)            ２２）基本暗器 (throwing)
─────────────────────────────
「扬州武馆」所传授进阶武功
─────────────────────────────
  １）太祖长拳 (changquan)          ２）岳家散手 (sanshou)

学习命令是: xue 师傅名 武功技能 次数
TEXT
	]) );
	set("exits", ([
		"east" : __DIR__"wg_shilu-2",
	]));
	set("objects", ([
		__DIR__"npc/wg_jiaotou2" : 1,
	]) );
	set("no_fight",1);
	set("coor/x", 31);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

