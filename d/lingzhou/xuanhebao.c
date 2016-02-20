// Room: /lingzhou/xuanhebao.c
// Java Sep.23 1998

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "宣和堡");
	set("long", @LONG
这里就是西北小镇宣和堡，南面是黄河，西面是沙漠，只有这里
有一片不大的绿洲，住户们都是从关内迁移过来的，大多以经营手工
艺品为生, 这里的手织羊毛挂毯颇有名气。每逢初一、十五附近的百
姓都来到这摆渡过河到关内去赶集。河案边熙熙攘攘，人们都在争着
叫(yell)船过河。
LONG	);
	set("exits", ([
		"northeast" : __DIR__"mingshazhou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "lingzhou");
	set("coor/x", -18000);
	set("coor/y", 32000);
	set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "河");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只听得风浪中隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("wait_msg",       "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "艄公把踏脚板收了起来，竹篙一点，扁舟向河中撑去。\n");
  set("leave_msg_in",   "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向河中撑去。\n");
  set("come_msg_in",    "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("item_desc/river", HIC "\n只见近岸处有一条渡船，也许大声喊("
                         HIY "yell" HIC ")一声船家(" HIY "boat" HIC
                        ")就\n能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏河而过。\n" NOR);
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
黄河上的小舟都是这种很简陋的小舟。一位中年艄公正站在船尾
吃力地掌舵，一位膀子壮硕的小伙子也在船头用劲地划水撑船。黄河
水流湍急，船下滑很快，横渡却很慢。
LONG );
  set("to",         "/d/yongdeng/guchangcheng");  // 船的终点 /*   必选   */
	setup();
}