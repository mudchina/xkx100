// /d/city/feixingqi.c

#include <ansi.h>
inherit  ROOM;
string look_ban();

void create ()
{
	set ("short", "飞行棋室");
	set ("long", @LONG
这里是飞行棋室，室中正中是一副雕花红木大棋盘，上书“翱翔苍
穹”四字，横竖摆着一些战机。墙上钉了一块小木版 (ban)，用红字绿
线勾画了游戏玩法。
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/flyer" : 1,
	]));
	set("item_desc", ([ 
		"ban": (: look_ban :),
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"qiyiting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 21);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
string look_ban()
{
        return
"			飞行棋

——[开始游戏]—————
加入游戏：join　　　　　
开始游戏：start
重置游戏：reset qi

——[游戏命令]—————
　摇骰子：toss
查看情况：view
移动棋子：move a|b|c|d
催促玩家：next

——[游戏规则]—————
    飞行棋，大家打小就都玩过，丢骰子就是，丢出六来才能起飞，别
的也不用多说了吧？\n";
}
