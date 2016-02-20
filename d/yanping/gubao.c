// Room: /d/yanping/gubao.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "古堡");
	set("long", @LONG
仰望坎顶，视若关堡雄镇云天，关口为石拱门，内有一木构亭榭和
宋代的石砌古堡。堡内悬挂大总统曹锟题赠重修古道的邑人王堂选“义
问宣昭”木匾。古堡东面拱门前有六株千年柳杉，相传是杨八妹的哨兵，
经仙人点化而矗立于此，其枝叶招展，横亘数里，蔚为壮观，即使远在
延平城东，也可瞥见其挺拔入云的雄姿。登临坎顶，可饱览群山秀色。
放眼远眺，城区民舍鳞次栉比，闽江之水如银带环绕，气派雄伟。古人
曰：“晨观日出，延平城郭增绚丽；暮看夕落，百里梯田披彩霞。”
LONG );
	set("exits", ([
		"west"      : __DIR__"mangdangshan",
		"southwest" : __DIR__"yanxianshan",
		"northdown" : __DIR__"yidao2",
		"southdown" : __DIR__"banyanting",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yanping");
	setup();
	replace_program(ROOM);
}
