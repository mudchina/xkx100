// /d/city/dahuashaizi.c

#include <ansi.h>
inherit  ROOM;
string look_ban();

void create ()
{
	set ("short", "大话骰子屋");
	set ("long", @LONG
这里是大话骰子屋，屋子中间摆着一个大案台，案台面上，用草字
刻着“吹牛不要本钱”字样。案台上有两个竹筒，覆筒下面各有五个骰
子，酒酣耳热之后，尽可“大话”一番。墙上钉了一块小木版 (ban)，
密密麻麻大致写了基本玩法。
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/dahuashaizi" : 1,
	]));
	set("item_desc", ([ 
		"ban": (: look_ban :),
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"shaiziting",
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
"			大话骰子

——[开始游戏]—————
加入游戏：join	开始游戏：start	重置游戏：reset se
——[游戏命令]—————
摇骰子：toss	查看骰子：view [玩家ID]
准备结束：finish/deal
拆穿大话：dahua [玩家ID]
猜测骰子：guess 骰子数量 骰子点数
　　　　　或者 g 骰子数量 骰子点数
催促玩家：next
——[其它命令]—————
计数器：showc	猜测日志：history
——[旁观命令]—————
观战命令：visit [-d] 玩家ID
                邀请其它玩家观看你的游戏。
                加参数 -d 表示删除该玩家的观看资格。
——[游戏规则]—————
    这个游戏，凡是上过酒吧、歌厅的，都应该玩过。不多说啦，
很考验智慧的。\n";
}
