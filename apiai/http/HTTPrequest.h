#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>
#include <map>

namespace ai {

class HTTPRequest
{
    class HTTPRequestImpl;
    std::unique_ptr<HTTPRequestImpl> impl;
public:
    HTTPRequest(const std::string &URL);

    const std::string &getBody() const;
    void setBody(const std::string &value);

    const std::string &getURL() const;
    void setURL(const std::string &value);

    const std::map<std::string, std::string> &getHeaders() const;
    void setHeaders(const std::map<std::string, std::string> &value);

    HTTPRequest& addHeader(const std::string &name, const std::string &value);

    std::string perform();

    virtual ~HTTPRequest();
};
}

#endif // HTTPREQUEST_H
