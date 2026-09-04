/**
 * @file AgentHttpController.h
 * @brief Agent HTTP 控制器 —— 处理所有 /api/agent/* 路由。
 *
 * 构造函数接收 IAgentDirectory* 和 IAgentStatusService*，
 * 通过 processRequest 分发请求（签名与 HttpApiExecutor 一致）。
 * 路由表：
 *   GET  /api/agent/list
 *   GET  /api/agent/status?agent=XXX&refresh=0|1
 *   POST /api/agent/alias/set
 *   POST /api/agent/alias/clear
 */

#ifndef AGENT_HTTP_CONTROLLER_H
#define AGENT_HTTP_CONTROLLER_H

#include "agents/contracts/AgentContracts.h"

#include <QByteArray>
#include <QString>

class AgentHttpController {
public:
    /**
     * @brief 构造控制器。
     * @param directory   已初始化的智能体目录（不可为空）
     * @param statusService 已初始化的状态服务（不可为空）
     */
    AgentHttpController(IAgentDirectory *directory, IAgentStatusService *statusService);

    /**
     * @brief 处理一条 HTTP 请求。
     * @param method     HTTP 方法（大写，如 "GET" / "POST"）
     * @param path       路径，如 "/api/agent/list"
     * @param query      查询字符串（不含 ?），可为空
     * @param body       POST 原始 body
     * @param httpStatus 输出 HTTP 状态码
     * @return JSON 响应体
     */
    QByteArray processRequest(const QString &method, const QString &path,
                              const QString &query, const QByteArray &body,
                              int *httpStatus);

private:
    QByteArray handleList(int *httpStatus);
    QByteArray handleStatus(const QString &query, int *httpStatus);
    QByteArray handleAliasSet(const QByteArray &body, int *httpStatus);
    QByteArray handleAliasClear(const QByteArray &body, int *httpStatus);

    IAgentDirectory *directory_;
    IAgentStatusService *statusService_;
};

#endif // AGENT_HTTP_CONTROLLER_H
