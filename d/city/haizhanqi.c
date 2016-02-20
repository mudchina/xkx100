// /d/city/haizhanqi.c

#include <ansi.h>
inherit  ROOM;
string look_ban();

void create ()
{
	set ("short", "海战棋室");
	set ("long", @LONG
这里是很现代气息的海战棋室，室中正中是一副大棋盘，上书“击
水沧海”四字，横竖摆着一些战船。墙上钉了一块小木版 (ban)，密密
麻麻大致写了征战要诀。
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/seawar" : 1,
	]));
	set("item_desc", ([ 
		"ban": (: look_ban :),
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"qiyiting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 19);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
string look_ban()
{
        return
"			海战棋

——[开始游戏]—————
加入游戏：join		开始游戏：start	重置游戏：reset board
——[船只布置]—————
放置船只：place X坐标 Y坐标		随机放置：rplace
取消放置：unplace X坐标 Y坐标		放置结束：finish
——[火力布置]—————
放置火力：fire X坐标 Y坐标		放置结束：finish
取消放置：unfire X坐标 Y坐标
——[观战命令]—————
观战命令：visit [-d] 玩家ID		邀请其它玩家观看游戏
				加参数-d删除该玩家的观看资格
——[游戏规则]—————
    该游戏是两人游戏。游戏开始时候，每人有十艘船。
    在准备阶段，各人把自己的船放置于自己的棋盘上。当各人都准备
好以后，进入战斗阶段。
    在战斗阶段，各人决定攻击的位置。每一艘船有一次攻击机会。在
完成攻击设置以后，进入战斗状态。系统根据双方的攻击设置进行攻击，
当攻击位置上有敌方船，则可以把对方该船击毁。被击毁的船丧失攻击
能力。
    在所有攻击结束以后，重新进入攻击设置。如此循环，直到一方的
船全部被击毁。\n";
}
