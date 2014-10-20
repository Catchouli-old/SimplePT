#ifndef SIMPLEPT_SIMPLEPT_H
#define SIMPLEPT_SIMPLEPT_H

#include <app/Application.h>

namespace pt
{
    class SimplePT
        : public rend::Application
    {
    public:
        SimplePT();

        void update(double dt) override;
        void render() override;

    private:

    };
}

#endif /* SIMPLEPT_SIMPLEPT_H */